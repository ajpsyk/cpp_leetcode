#include <vector>
#include <queue>

std::vector<int> sort_a_k_sorted_array(std::vector<int> nums, int k)
{
    std::vector<int> res;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (const int& num : nums)
    {
        minHeap.push(num);
        if (minHeap.size() > k + 1)
        {
            res.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    while (!minHeap.empty())
    {
        res.push_back(minHeap.top());
        minHeap.pop();
    }
        
    return res;
}
