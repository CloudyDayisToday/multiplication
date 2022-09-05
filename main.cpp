#include <iostream>
#include <iomanip>
#include "include/multiplication.h"
#include "include/sorting.h"

void call_multiplication_algor(void);
void call_sorting_algor(void);

int main(int args, char **argv)
{
    call_sorting_algor();
}

void call_multiplication_algor()
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

void call_sorting_algor()
{
    std::vector<int> array{6, 3, 10, 100, 35, 8, 55, 9, 8, 9, 93};
    SortAlgor sort(array, array.size());
    // sort.insertion_sort(array, array.size());
    // sort.selection_sort(array, array.size());
    array = sort.top_down_merge_sort(array, array.size()-1);
    for (int i : array)
    {
        std::cout << i << " " ;
    }
    std::cout << std::endl;
    // sort.heap_sort();
    // sort.quick_sort_handle();
    // sort.comb_sort();
    // for (int i : array)
    // {
    //     std::cout << i << " " ;
    // }
    // std::cout << std::endl;
}
