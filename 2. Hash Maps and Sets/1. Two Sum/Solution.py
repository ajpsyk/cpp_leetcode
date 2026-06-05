from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        complements = {}

        for index, num in enumerate(nums):
            complement_index = complements.get(target - num)
            if complement_index is not None:
                return [complement_index, index]
            
            complements[num] = index
        
        return []