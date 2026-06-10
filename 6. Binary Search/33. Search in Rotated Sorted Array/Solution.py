from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while (left <= right):
            middle = left + (right - left) // 2
            middle_num = nums[middle]

            if middle_num == target: return middle

            if (nums[left] <= middle_num):
                if (nums[left] <= target < middle_num):
                    right = middle - 1
                else:
                    left = middle + 1
            else:
                if (middle_num < target <= nums[right]):
                    left = middle + 1
                else:
                    right = middle - 1
        
        return -1
        