from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        left = len(nums) - 2

        while left >= 0 and nums[left] >= nums[left + 1]:
            left -= 1
        
        if left == -1:
            nums.reverse()
            return
        
        right = len(nums) - 1

        while nums[right] <= nums[left]:
            right -= 1
        
        nums[left], nums[right] = nums[right], nums[left]

        nums[left + 1:] = reversed(nums[left + 1:])