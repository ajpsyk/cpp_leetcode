from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first_position = -1
        last_position = -1

        left = 0
        right = len(nums) - 1

        while left < right:
            middle = left + (right - left) // 2

            if nums[middle] >= target: right = middle
            else: left = middle + 1

        
        if nums and nums[right] == target: first_position = right


        left = 0
        right = len(nums) - 1

        while left < right:
            middle = left + (right - left) // 2 + 1

            if nums[middle] <= target: left = middle
            else: right = middle - 1

        if nums and nums[left] == target: last_position = left

        return [first_position, last_position]