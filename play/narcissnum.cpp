#include <iostream>
#include <string>
#include <cmath>

bool narcissistic(int value)
{
    std::string str_val = std::to_string(value);
    int nsum = 0;
    for (int c : str_val)
    {
        nsum += pow(c - '0',str_val.length());
    }   
    if (nsum == value) return true;
    return false;
}

int main(int argc, char** argv)
{
    int num = std::stoi(argv[1]);
    if (narcissistic(num))
        std::cout << "true\n";
    else
        std::cout << "false\n";
}