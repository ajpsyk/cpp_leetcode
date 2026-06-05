#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res {};

        for (int i = 0; i < nums.size(); ++i)
        {
            int a = nums[i];

            if (i > 0 && a == nums[i - 1])
            {
                continue;
            }

            if (a > 0)
            {
                break;
            }

            std::vector<std::vector<int>> pairs = twoSum(nums, i + 1, -a);

            for (auto& pair: pairs)
            {
                res.push_back({a, pair[0], pair[1]});
            }
        }

        return res;

    }

    std::vector<std::vector<int>> twoSum(std::vector<int>& nums, int left, int target)
    {
        int right = nums.size() - 1;
        std::vector<std::vector<int>> pairs {};

        while (left < right)
        {
            int sum = nums[left] + nums[right];

            if (sum == target)
            {
                pairs.push_back({nums[left], nums[right]});
                ++left;

                while (left < right && nums[left] == nums[left - 1])
                {
                    ++left;
                }
            }

            else if (sum < target)
            {
                ++left;
            }

            else
            {
                --right;
            }

        }

        return pairs;
    }
};