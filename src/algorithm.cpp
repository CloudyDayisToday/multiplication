#include <iostream>
#include "../include/algorithm.h"

int Algorithm::euclidean_algorithm(int num1, int num2)
{
    // Common divisor
    while (num1 != num2)
    {
        if (num1 > num2)
            num1 = num1 - num2;
        else
            num2 = num2 - num1;
    }
    return num1;
}

int Algorithm::euclidean_recursion(int num1, int num2)
{
    if (num2 == 0)
        return num1;
    else
        return euclidean_recursion(num2, num1%num2);
}

int Algorithm::boyer_moore_algorithm (std::vector<int> &array, std::size_t size)
{
    int majority, count = 0;
    for (int data : array)
    {
        
        if (count == 0)
        {
            majority = data, count = 1;
        }
        else
            (majority == data) ? ++count : --count;
    }
    return majority;
}

