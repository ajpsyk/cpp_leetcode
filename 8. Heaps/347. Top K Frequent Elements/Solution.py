from typing import List
from collections import Counter
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_map = Counter(nums)
        min_heap = []

        for val, freq in freq_map.items():
            heapq.heappush(min_heap, (freq, val))

            if len(min_heap) > k:
                heapq.heappop(min_heap)

        res = [heapq.heappop(min_heap)[1] for _ in range(k)]
        return res
                