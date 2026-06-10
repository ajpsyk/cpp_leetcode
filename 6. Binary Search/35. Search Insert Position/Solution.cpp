#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] < target) left = middle + 1;
            else right = middle;
        }

        return left;
    }
};