#include <vector>

class SearchAlgor
{
private:
    std::vector<int> &array;
    std::size_t size;
    int target;
public:
    SearchAlgor(std::vector<int> &array, std::size_t size, int target) : array(array), size(size), target(target)
    {}
    ~SearchAlgor(){}
    int binary_search();
};