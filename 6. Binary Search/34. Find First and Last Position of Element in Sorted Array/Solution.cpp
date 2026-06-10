#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int first_position = -1;

        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] >= target) right = middle;
            else left = middle + 1;
        }

        if (nums.size() && nums[right] == target) first_position = right;

        int last_position = -1;

        left = 0;
        right = nums.size() - 1;

        while (left < right)
        {
            int middle = left + (right - left) / 2 + 1;
            if (nums[middle] <= target) left = middle;
            else right = middle - 1;
        }

        if (nums.size() && nums[left] == target) last_position = left;
        return {first_position, last_position};
    }
};