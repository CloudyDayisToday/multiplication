#include <vector>
#include <string>
#include <unordered_map>

struct Node
{
    int data;
    Node *next;
};

class Algorithm
{
private:
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> rank;
    int partition (std::vector<int> &vec, int left, int right, int pindex);
    int find_root(int k);
    
public:
    int euclidean_algorithm (int num1, int num2);
    int euclidean_recursion (int num1, int num2);
    int boyer_moore_algorithm (std::vector<int> &array, std::size_t size);
    int quick_select_algorithm (std::vector<int> &array, int left, int right, int ith);
    void kmp_search_algorithm (std::string vec, std::string pattern);
    void make_set(std::vector<int> const &vec);
    void union_algorithm(int a, int b);
    void printSets(std::vector<int> &vec, Algorithm &ds);
    void push (Node*& headref, int data);
    bool detection_algorithm(Node *head);
};
