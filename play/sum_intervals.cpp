#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

int sum_intervals(std::vector<std::pair<int,int>>&& intervals)
{
    std::sort(
        intervals.begin(),
        intervals.end(),
        [](std::pair<int,int> x, std::pair<int,int> y){
            return x.first < y.first && x.second < y.second;
        }
    );
    for (auto& a : intervals)
    {
        std::cout << "{" << a.first << ',' << a.second << "}, ";
    }
    std::cout << std::endl;
    int sum = 0;
    auto p = intervals.begin();
    int f = p->first;
    int s = p->second;
    ++p;
    for (; p < intervals.end(); ++p)
    {
        std::cout << "f=" << f << " s=" << s << " " << p->first << ',' << p->second << std::endl;
        if (p->first < s){
            s = (s < p->second)? p->second : s;
            continue;
        }
        sum += s - f;
        f = p->first;
        s = p->second;
    }
    sum += s - f;
    std::cout << "sum=" << sum << std::endl;
    return sum;
}

int main()
{
    std::cout <<
    sum_intervals( {
        {1, 2},
        {6, 10},
        {11, 15}
    } ) << std::endl;
    std::cout << "should be 9" << std::endl;

    std::cout <<
    sum_intervals( {
        {1, 4},
        {7, 10},
        {3, 5}
    } ) << std::endl;
    std::cout << "should be 7" << std::endl;

    std::cout << 
    sum_intervals({
        {-352,489},{213,365},{-72,71},{-129,332},{-135,168},{101,420},{254,417},{140,447},{-426,15},{327,438},{436,476},{130,134},{228,342},{155,323},{270,281},{-347,382}
    }) << std::endl << "should be 915" << std::endl;
}