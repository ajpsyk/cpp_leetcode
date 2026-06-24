#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_map;

        for (auto const& num : nums)
        {
            ++freq_map[num];
        }

        typedef std::pair<int, int> pair;
        std::priority_queue<pair, std::vector<pair>, std::greater<pair>> min_heap;

        for (auto const& [val, freq] : freq_map)
        {
            min_heap.push({freq, val});

            if (min_heap.size() > k)
            {
                min_heap.pop();
            }
        }

        std::vector<int> res;

        while (!min_heap.empty())
        {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return res;

    }
};