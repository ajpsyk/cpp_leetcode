from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        prefix_sum = 0
        freq_map = {0:1}

        for num in nums:
            prefix_sum += num
            if prefix_sum - k in freq_map:
                res += freq_map[prefix_sum - k]
            freq_map[prefix_sum] = freq_map.get(prefix_sum, 0) + 1
        
        return res