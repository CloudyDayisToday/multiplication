#include <iostream>
#include <iomanip>
#include "multiplication.h"

int main(int args, char **argv)
{
    int64_t x, y, sum;
    sum = 0;
    std::cout << "X : ";
    std::cin >> x;
    std::cout << "Y : ";
    std::cin >> y;
    int64_t result = karatsuba_algorithm(x, y);
    int64_t result2 = peasant_algorithm(x, y);
    int64_t result3 = quarter_square_algorithm(x, y);
    std::cout << std::setw(18) << std::left << "Karatsuba : " << x << " * " << y << " = " << result << std::endl;
    std::cout << std::setw(18) << std::left<< "Peasant : " << x << " * " << y << " = " << result2 << std::endl;
    std::cout << std::setw(18) << std::left<< "Quarter Square : " << x << " * " << y << " = " << result3 << std::endl;
}