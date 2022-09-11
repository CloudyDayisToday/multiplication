#include <iostream>
#include <iomanip>
#include "include/multiplication.h"
#include "include/sorting.h"
#include "include/search.h"
#include "include/algorithm.h"

void call_multiplication_algor(void);
void call_sorting_algor(void);
void call_search_algor(void);
void call_algor(void);

int main(int args, char **argv)
{
    call_algor();
}

void call_multiplication_algor()
{
    int64_t x, y, sum;
    sum = 0;
    std::cout << "X : ";
    std::cin >> x;
    std::cout << "Y : ";
    std::cin >> y;
    MultiAlgor multi_algor;
    int64_t result = multi_algor.karatsuba_algorithm(x, y);
    int64_t result2 = multi_algor.peasant_algorithm(x, y);
    int64_t result3 = multi_algor.quarter_square_algorithm(x, y);
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
    // array = sort.top_down_merge_sort(array, array.size()-1);
    // for (int i : array)
    // {
    //     std::cout << i << " " ;
    // }
    //std::cout << std::endl;
    // sort.heap_sort();
    // sort.quick_sort_handle();
    // sort.comb_sort();
    sort.radix_sort();
    for (int i : array)
    {
        std::cout << i << " " ;
    }
    std::cout << std::endl;
}

void call_search_algor()
{
    int target = 35;
    std::vector<int> array{6, 3, 10, 100, 35, 8, 55, 9, 8, 9, 93};
    SortAlgor sort(array, array.size());
    sort.radix_sort();
    SearchAlgor search(array, array.size(), target);
    int index = search.binary_search();
    for (int i : array)
    {
        std::cout << i << " " ;
    }
    std::cout << std::endl;
    std::cout << index << std::endl;
}

void call_algor()
{
    std::vector<int> array{10, 3, 5, 8, 10, 11, 55, 9, 8, 9, 93};
    Algorithm algor;
    int divisor = algor.euclidean_algorithm(114, 57);
    std::cout << "Euclidean algor : " << divisor << std::endl;
    divisor = algor.euclidean_recursion(114, 57);
    std::cout << "Euclidean recursion algor : " << divisor << std::endl;
    int majority = algor.boyer_moore_algorithm(array, array.size());
    std::cout << "Boyer Moore algor : " << majority << std::endl;
    int ith = algor.quick_select_algorithm(array, 0, array.size()-1, 0);
    std::cout << "Quick select algor :  " << ith << std::endl;
    std::string text = "feweooifjeioohgwueaghweooiweoo";
    std::string pattern = "weoo";
    algor.kmp_search_algorithm(text, pattern);

    std::vector<int> vec1{5, 6, 9, 2, 3};
    algor.make_set(vec1);
    algor.printSets(vec1, algor);
    algor.union_algorithm(5, 9);
    algor.printSets(vec1, algor);

    std::vector<int> tree{1, 2, 4, 6, 2, 1};
    Node *head = nullptr;
    for (int key : tree)
        algor.push(head, key);
    head->next->next->next = head->next->next;
    if (algor.detection_algorithm(head))
        std::cout << "cycle found!\n";
    else
        std::cout << "cycle not found!\n";
}