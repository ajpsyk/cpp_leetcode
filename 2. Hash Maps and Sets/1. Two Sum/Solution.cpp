#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> complements {};


        for (int i = 0; i < nums.size(); ++i)
        {   
            auto it = complements.find(target - nums[i]);
            if (it != complements.end())
            {
                return {it->second, i};
            }

            complements[nums[i]] = i;
        }

        return {};
    }
};