#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int res = 0;
        int prefixSum = 0;
        std::unordered_map<int, int> freqMap = {{0,1}};

        for (const int& num : nums)
        {
            prefixSum += num;

            const auto& it = freqMap.find(prefixSum - k);
            if (it != freqMap.end())
            {
                res += it->second;
            }

            ++freqMap[prefixSum];
        }

        return res;
    }
};