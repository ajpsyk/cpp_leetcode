#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (!nums.size()) return 0;
        int longest_chain = 0;

        std::unordered_set<int> num_set;
        for (auto& num : nums)
        {
            num_set.insert(num);
        }

        for (auto& num : num_set)
        {
            if (!num_set.count(num - 1))
            {
                int curr_num = num;
                int curr_chain = 1;

                while (num_set.count(curr_num + 1))
                {
                    curr_num += 1;
                    curr_chain += 1;
                }

                if (longest_chain < curr_chain) longest_chain = curr_chain;
            }
        }

        return longest_chain;
    }
};