/*
    SUM OF INTERVALS
    1. the point is to take a list of intervals, 
    2. determine actual intervals (if some overlap), 
    3. and sum up their sizes
*/

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

void print_intervals(const std::vector<std::pair<int,int>>& intervals)
{
    std::cout << "{ ";
    for (auto& p : intervals)
    {
        std::cout << "{" << p.first << ',' << p.second << "}" << ((p < intervals.back()) ? ", " : "");
    }
    std::cout << " }" << std::endl;
}

// MY SOLUTION:
int sum_intervals(std::vector<std::pair<int,int>>& intervals)
{
#ifdef DEBUG
    std::cout << "unsorted: \n";
    print_intervals(intervals);
#endif
    std::sort(
        intervals.begin(),
        intervals.end(),
        [](std::pair<int,int> x, std::pair<int,int> y){
            return x.first < y.first || (x.first == y.first && x.second < y.second);
        }
    );
#ifdef DEBUG
    std::cout << "sorted: \n";
    print_intervals(intervals);
#endif
    int sum = 0;
    auto p = intervals.begin();
    int f = p->first;
    int s = p->second;
    ++p;
    for (; p < intervals.end(); ++p)
    {
        if (p->first < s){
            s = (s < p->second)? p->second : s;
            continue;
        }
        sum += s - f;
        f = p->first;
        s = p->second;
    }
    sum += s - f;
    return sum;
}

using Interval_t = std::vector<std::pair<int,int>>;

// OTHER SOLUTIONS:
int sum_intervals_similar(Interval_t v) {
    std::sort(
        v.begin(), v.end(), 
        [](auto x, auto y)
        {
            // uses ? instead of my condition
            return x.first != y.first ? x.first < y.first : x.second < y.second;
        }
    );
    int r = 0, last = v[0].first;
    for (auto p : v) {
        int x = p.first, y = p.second;
        if (y <= last) continue;
        r += y - std::max(x, last);
        last = y;
    }
    return r;
}

#include <numeric>
int sum_intervals_accumulate(Interval_t intervals) { 
    std::sort(intervals.begin(), intervals.end());
    return std::accumulate(
        intervals.begin(), 
        intervals.end(), 
        0, 
        [boundary = intervals[0].first] (auto sum, const auto &p) mutable 
        { 
            if (boundary < p.second) 
            { 
                sum += p.second - std::max(boundary, p.first); 
                boundary = p.second; 
            } 
            return sum; 
        }
    );
}

// TESTING:
int test_interval(Interval_t&& intervals, int expected)
{
    int result = sum_intervals(intervals);
    //int result = sum_intervals_similar(intervals);
    //int result = sum_intervals_accumulate(intervals);
    std::cout << result << std::endl;
    std::cout << "should be " << expected << std::endl;
    return result == expected;
}

int main()
{
    std::cout << test_interval({{1, 2},{6, 10},{11, 15}},9) << std::endl;

    std::cout << test_interval( {{1, 4},{7, 10},{3, 5}}, 7) << std::endl;

    std::cout << test_interval({{-352,489},{213,365},{-72,71},{-129,332},{-135,168},{101,420},{254,417},{140,447},{-426,15},{327,438},{436,476},{130,134},{228,342},{155,323},{270,281},{-347,382}}, 915) << std::endl;

    std::cout << test_interval({ {-206,-1}, {-264,366}, {-16,14} },630) << std::endl;

}