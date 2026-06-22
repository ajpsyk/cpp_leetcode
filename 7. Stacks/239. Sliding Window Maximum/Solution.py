from typing import List
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        maximums = []
        order = deque()

        for i in range(len(nums)):
            if order and order[0] < i - k + 1:
                order.popleft()
            
            while order and nums[order[-1]] < nums[i]:
                order.pop()
            
            order.append(i)
            
            if i >= k - 1:
                maximums.append(nums[order[0]])
        
        return maximums