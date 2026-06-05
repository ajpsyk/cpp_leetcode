#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        
        int pivot = nums.size() - 2;

        while (pivot >= 0 and nums[pivot] >= nums[pivot + 1])
        {
            --pivot;
        }

        if (pivot == -1)
        {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        int rightmost_succesor = nums.size() - 1;

        while (nums[rightmost_succesor] <= nums[pivot])
        {
            --rightmost_succesor;
        }

        int pivotNum = nums[pivot];
        nums[pivot] = nums[rightmost_succesor];
        nums[rightmost_succesor] = pivotNum;

        std::reverse(nums.begin() + pivot + 1, nums.end());
            
    }
};