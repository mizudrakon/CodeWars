#include <string>
#include <iostream>
#include <format>

std::string rgb_to_hex(int r, int g, int b)
{
    std::string result("000000");
    auto result_it = --result.end();
    for (auto num : {b,g,r})
    {
        int h{};
        for (int i = 2; i > 0; --i)
        {
            num = (num < 0) ? 0 : (num < 256) ? num : 255;
            h = num % 16;
            *result_it = ((h < 10) ? h + '0' : h - 10 + 'A');
            num /= 16;
            --result_it;
        }
    }
    return result;
}

// There is a way using FORMAT:
#include <algorithm>
#include <format>

std::string rgb_to_hex_format(int r, int g, int b)
{
    return std::format("{:02X}{:02X}{:02X}", std::clamp(r, 0, 255), std::clamp(g, 0, 255), std::clamp(b, 0, 255));
    // clamp is from algorithm and does the same as mine "num = (num < 0) ? 0 : (num < 256) ? num : 255"
}

// Another way using streams
#include <iomanip>

std::string rgb_to_hex_streams(int r, int g, int b)
{
  std::stringstream stream;  
  stream << std::setfill('0') << std::uppercase << std::setw(2) << std::hex << std::clamp(r, 0, 255);
  stream << std::setfill('0') << std::uppercase << std::setw(2) << std::hex << std::clamp(g, 0, 255);
  stream << std::setfill('0') << std::uppercase << std::setw(2) << std::hex << std::clamp(b, 0, 255);
  return stream.str();
}

int main()
{
    std::cout << rgb_to_hex(0,0,0) << std::endl;
    std::cout << rgb_to_hex(255,255,255) << std::endl;
    std::cout << rgb_to_hex(255,255,300) << std::endl;
    std::cout << rgb_to_hex(148,0,211) << std::endl;
    std::cout << rgb_to_hex_format(-12,255,125) << std::endl;

    //std::cout << 'A' + 15 << std::endl;
}