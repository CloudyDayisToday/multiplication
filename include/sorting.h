#include <vector>



class SortAlgor
{
private:

    std::vector<int> &array;

    std::size_t size;

    std::vector<int> merge (std::vector<int> &left, std::vector<int> &right);
    
    void sift_down (std::vector<int> &array, int start, int end);
    
    void heapify (std::vector<int> &array, std::size_t size);

    void quick_sort (std::vector<int> &array, int low, int high);

    int partition (std::vector<int> &array, int low, int high);

    void counting_sort (std::vector<int> &array, int max);

public:

    SortAlgor(std::vector<int> &array, std::size_t size) : array(array), size(size){}

    ~SortAlgor(){}

    void insertion_sort ();

    void selection_sort ();

    std::vector<int> top_down_merge_sort (std::vector<int> &array, std::size_t size);

    void heap_sort ();

    void quick_sort_handle ();

    void shell_sort ();

    void bubble_sort ();

    void comb_sort ();

    std::vector<int> counting_map_sort ();

    void radix_sort ();
};

