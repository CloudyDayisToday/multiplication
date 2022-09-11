#include <iostream>
#include <random>
#include "../include/algorithm.h"

int Algorithm::partition (std::vector<int> &vec, int left, int right, int pindex)
{
    int pivot = vec[pindex];

    std::swap(vec[pindex], vec[right]);
    pindex = left;

    for (int i = left; i < right; ++i)
    {
        if (vec[i] <= pivot)
        {
            std::swap(vec[i], vec[pindex]);
            pindex++;
        }
    }
    std::swap(vec[pindex], vec[right]);
    return pindex;
}

int Algorithm::find_root(int k)
{
    if (parent[k] != k)
    {
        parent[k] = find_root(parent[k]);
    }

    return parent[k];
}

/*-----------------------------------------------------PUBLIC FUNCTION----*/
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

int Algorithm::quick_select_algorithm (std::vector<int> &array, int left, int right, int ith)
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(left+1, right);
    if (left == right) return array[left];

    int pindex = floor(rand()%(right - left + 1) + left);
    int pivot = partition (array, left, right, pindex);

    if (ith == pindex)
        return array[ith];
    else if (ith < pindex)
        return quick_select_algorithm(array, left, pindex-1, ith);
    else
        return quick_select_algorithm(array, pindex+1, right, ith);
}

void Algorithm::kmp_search_algorithm (std::string text, std::string pattern)
{
    int m = text.length(),n = pattern.length();

    if (n == 0) 
    {   
        std::cout << "The pattern occurs with shift 0";
        return;
    }
    if (m < n) 
    {
        std::cout << "Pattern not found";
        return;
    }

    int next[n + 1];
    std::fill_n(next, pattern.size()+1, 0);

    for (int i = 1; i < n; ++i)
    {
        int j = next[i+1];

        while (j > 0 && pattern[j] != pattern[i])
            j = next[j];

        if (j > 0 || pattern[j] == pattern[i])
            next[i + 1] = j + 1;
    }


    for (int i = 0, j = 0; i < m; ++i)
    {
        if (text[i] == pattern[j])
        {
            if (++j == n)
                std::cout << "The pattern occurs with shift " << i - j + 1 << std::endl;
        } else if (j > 0)
        {
            j = next[j];
            --i;
        }
    }
}

void Algorithm::make_set(std::vector<int> const &vec)
{
    for (int i : vec)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}


void Algorithm::printSets(std::vector<int> &vec, Algorithm &ds)
{
    for (int i : vec)
    {
        std::cout << ds.find_root(i) << " ";
    }
    std::cout << std::endl;
}

void Algorithm::union_algorithm(int a, int b)
{
    int x = find_root(a);
    int y = find_root(b);

    if (x == y) return;
    if (rank[x] > rank[y]) parent[y] = parent[x];
    else if (rank[x] < rank[y]) parent[x] = parent[y];
    else
    {
        parent[x] = y;
        ++rank[y];
    }
}

void Algorithm::push (Node*& headref, int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = headref;
    headref = newNode;
}


bool Algorithm::detection_algorithm(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}
