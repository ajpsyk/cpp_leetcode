#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int index = left + (right - left) / 2;
            int middle = nums[index];

            if (middle == target) return index;

            if (middle <= nums[right])
            {
                if (middle < target && target <= nums[right]) left = index + 1;
                else right = index - 1;
            }
            else
            {
                if (nums[left] <= target && target < middle) right = index - 1;
                else left = index + 1;
            }
        }

        return -1;
    }
};