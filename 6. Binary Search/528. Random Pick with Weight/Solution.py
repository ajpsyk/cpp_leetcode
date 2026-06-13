from typing import List
import random

class Solution:

    def __init__(self, w: List[int]):
        self.prefix_sums = [w[0]]
        for i in range(1, len(w)):
            self.prefix_sums.append(self.prefix_sums[-1] + w[i])

    def pickIndex(self) -> int:
        target = random.randint(1, self.prefix_sums[-1])

        left = 0
        right = len(self.prefix_sums) - 1

        while left < right:
            middle = (right + left) // 2

            if self.prefix_sums[middle] < target:
                left = middle + 1
            else:
                right = middle
        
        return left