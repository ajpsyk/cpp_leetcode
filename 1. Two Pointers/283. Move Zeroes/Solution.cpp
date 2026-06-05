#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int i = 0;

        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] != 0)
            {
                int left = nums[i];
                nums[i] = nums[j];
                nums[j] = left;
                ++i;
            }
        }
    }
};