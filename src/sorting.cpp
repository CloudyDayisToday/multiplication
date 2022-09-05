#include <iostream>
#include <iterator>
#include <tuple>
#include <cassert>
#include <cmath>
#include "../include/sorting.h"

template<typename T>
void pop_front(std::vector<T> &vec)
{
    assert(!vec.empty());
    vec.erase(vec.begin());
}

std::vector<int> SortAlgor::merge(std::vector<int> &left, std::vector<int> &right)
{
    std::vector<int> result;
    while(!left.empty() && !right.empty())
    {
        if (left.front() <= right.front())
        {
            result.push_back(left.front());
            pop_front(left);
        } else
        {
            result.push_back(right.front());
            pop_front(right);
        }
    }

    while (!left.empty())
    {
        result.push_back(left.front());
        pop_front(left);
    }
    while (!right.empty())
    {
        result.push_back(right.front());
        pop_front(right);
    }
    return result;
}

void SortAlgor::sift_down (std::vector<int> &vec, int start, int end)
{
    int root = start;
    auto iLeftChild = [](int i){ return 2*i + 1; };
    while (iLeftChild(root) <= end)
    {
        int child = iLeftChild(root);
        int swap = root;

        if (vec[swap] < vec[child])
            swap = child;
        if (child + 1 <= end && vec[swap] < vec[child+1])
            swap = child + 1;
        if (swap == root)
            return;
        else
        {
            std::swap(vec[root], vec[swap]);
            root = swap;
        }
    }
}

void SortAlgor::heapify (std::vector<int> &vec, std::size_t size)
{
    auto iParent = [](int i){ return floor((i-1)/2); };
    int start = iParent(size-1);

    while(start >= 0)
    {
        sift_down(vec, start, size-1);
        --start;
    }
}

int SortAlgor::partition (std::vector<int> &vec, int low, int high)
{
    int pivot = vec[high];

    int temp = low - 1;
    for (int i = low; i < high; ++i)
    {
        if (vec[i] <= pivot)
        {
            ++temp;
            std::swap(vec[temp], vec[i]);
        }
    }
    ++temp;
    std::swap(vec[temp], vec[high]);
    return temp;
}

void SortAlgor::quick_sort (std::vector<int> &vec, int low, int high)
{
    if (low >= high || low < 0) return;

    int pivot = partition(vec, low, high);
    quick_sort(vec, low, pivot-1);
    quick_sort(vec, pivot+1, high);
}

//-------------------------------------------------PUBLIC FUNCTION----//

void SortAlgor::insertion_sort()
{
    // Complexity O(N2)
    int i = 1, j;
    while (i < size)
    {
        int x = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > x)
        {
            array[j+1] = array[j];
            --j;
        }
        array[j+1] = x;
        ++i;
    }
    
    /* Recursion but input size should be len(array) - 1*/
    // if (size > 0)
    // {
    //     int x, j;
    //     insertion_sort(array, size-1);
    //     x = array[size];

    //     j = size-1;
    //     while (j >= 0 && array[j] > x)
    //     {
    //         array[j+1] = array[j];
    //         --j;
    //     }
    //     array[j+1] = x;
    // }
}

void SortAlgor::selection_sort ()
{
    // Complexity O(N2)
    for (int i = 0; i < size; ++i)
    {
        int min_it = i;
        for (int j = i+1; j < size; ++j)
        {
            min_it = array[j] < array[min_it] ? j : min_it; 
        }
        if (min_it != i)
            std::swap(array[i], array[min_it]);
       
    }
}

std::vector<int> SortAlgor::top_down_merge_sort (std::vector<int> &array, std::size_t size)
{
    if (size <= 1)
        return array;
    
    std::size_t half_size = size/2;  
    std::vector<int> left (array.begin(), array.begin() + half_size);
    std::vector<int> right (array.begin() + half_size, array.end());

    left = top_down_merge_sort(left, left.size());
    right = top_down_merge_sort(right, right.size());

    return merge(left, right);
}

void SortAlgor::heap_sort ()
{
    heapify (array, size);
    int end = size - 1;
    while (end > 0)
    {
        std::swap(array[end], array[0]);
        --end;
        sift_down(array, 0, end);
    }
}

void SortAlgor::quick_sort_handle ()
{
    quick_sort(array, 0, size-1);
}

void SortAlgor::shell_sort ()
{
    for (int itvl = size/2; itvl > 0; itvl/=2)
    {
        for (int i = itvl; i < size; ++i)
        {
            int temp = array[i];
            int j;
            for (j = i; (j >= itvl) && (array[j - itvl] > temp); j-=itvl)
            {
                array[j] = array[j - itvl];
            }
            array[j] = temp;
        }
    }
}

void SortAlgor::bubble_sort ()
{ 
    int n = size;
    while(true)
    {
        bool swapped = false;
        for (int i = 1; i < n; ++i)
        {
            if (array[i] < array[i-1])
            {
                std::swap(array[i], array[i-1]);
                swapped = true;
            }
        }
        --n;
        if (!swapped) break;
    }
}

void SortAlgor::comb_sort ()
{
    double shrink = 1.3;
    int gap = size;
    bool sorted = false;

    while (!sorted)
    {
        gap = floor(gap/shrink);

        if (gap <= 1)
        {
            sorted = true;
            gap = 1;
        }

        for (int i = 0; i < size - gap; ++i)
        {
            int sm = gap + i;
            if (array[i] > array[sm])
            {
                std::swap(array[i], array[sm]);
            }
        }
    }
}

std::vector<int> SortAlgor::count_sort ()
{
    int count[size+1], output[size];

    for (int i = 0; i < size-1; ++i)
    {
        int j = std::find(array, array+size-1, array[i]);
        count[j] += 1;
    }

    for (int i = 0; i < size; ++i)
    {
        count[i] += count[i-1];
    }

    for (int i = size-1; i >= 0; --i)
    {
        int j = array[i];
        count[j] -= 1;
        output[count[j]] = array[i];
    }
}
