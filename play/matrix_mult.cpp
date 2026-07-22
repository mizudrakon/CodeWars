#include <vector>
#include <iostream>
#include <format>

using matrix = std::vector<std::vector<int>>;

void print_mx(const matrix& m)
{
    for (auto& r : m){
        for (auto& c : r)
        {
            std::cout << std::format("{}, ", c);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int dot_product(int row, int col, const matrix& a, const matrix& b)
{
    int result = 0;
    for (size_t k = 0; k < a.size(); ++k)
    {
        //std::cout << std::format("{} + {} * {} = ",result,a[row][k],b[k][col]);
        result += a[row][k] * b[k][col];
        //std::cout << result << std::endl;
    }
    return result;
}

std::vector<std::vector<int>>
matrix_multiplication(const std::vector<std::vector<int>> &a,
    const std::vector<std::vector<int>> &b, size_t n) 
{
    auto c = a;
    for (size_t row = 0; row < n; ++row)
    {
        for (size_t col = 0; col < n; ++col)
        {
            c[row][col] = dot_product(row,col,a,b);
        }
    }
    return c;
}

int main()
{
    matrix a = {{1,2},{3,2}};
    matrix b = {{3,2},{1,1}};
    matrix c = matrix_multiplication(a,b,2);
    print_mx(c);
}