#include "../include/search.h"
#include <cmath>

int SearchAlgor::binary_search()
{
    int left = 0, right = size-1;

    while (left <= right)
    {
        int mid = floor((left+right)/2);
        if (array[mid] < target)
            left = mid+1;
        else if (array[mid] > target)
            right = mid-1;
        else 
            return mid;
    }
    return 0xFF;
}