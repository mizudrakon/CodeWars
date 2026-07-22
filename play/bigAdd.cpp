/*
    BIG ADD
    just adding big numbers given as string again...
*/
#include<string>
#include<iostream>
#include<algorithm>

std::string add(const std::string& a, const std::string& b)
{
    std::string result{};
    //iterators at the end -> one position after last
    auto a_it = --a.cend();
    auto b_it = --b.cend();
    int carry = 0;
    
    while (a_it >= a.cbegin() && b_it >= b.cbegin())
    {
        result += ((carry + *a_it + *b_it - 2*'0') % 10) + '0';
        carry = (carry + *a_it + *b_it - 2*'0') / 10;
        --a_it;
        --b_it;
    }

    auto it = a_it >= a.cbegin() ? a_it : b_it;
    auto it_begin = a_it >= a.cbegin() ? a.cbegin() : b.cbegin();

    while (it >= it_begin)
    {
        result += (carry + *it - '0') % 10 + '0';
        carry = (carry + *it - '0') / 10;
        --it;
    }
    if (carry)
        result += carry + '0';
    std::reverse(result.begin(),result.end());
    return result;
}

// first makes copies of both strings
std::string otherAdd(std::string a, std::string b)
{
    // makes new strings of the max length + 1 that start with zeros
    a = std::string(std::max(a.size(), b.size()) + 1 - a.size(), '0') + a;
    b = std::string(a.size() - b.size(), '0') + b;
    // can use for loop from back to start
    for (int i = a.size()-1, carry = 0; i >= 0; i--)
    {
        int sum = a[i] + b[i] - 96 + carry;
        carry   = sum / 10;
        a[i]    = sum % 10 + '0';
    }
    // result is a substring
    int i = a.find_first_not_of('0');
    return 0 <= i ? a.substr(i) : a.substr(0, 1);
}

int main(){
    std::cout << otherAdd("99","2") << std::endl;
    std::cout << otherAdd("12563090766930282724982009836281740585266309593989214585713317720313507755637811005834822079192474791062656386",
        "9943125278505497230444093") << std::endl;
    std::cout << "12563090766930282724982009836281740585266309593989214585713317720313507755637811005844765204470980288293100479" << std::endl;
}