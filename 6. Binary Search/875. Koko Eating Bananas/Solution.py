from typing import List
import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        max_speed = max(piles)
        min_speed = 1

        while (min_speed < max_speed):
            middle = min_speed + (max_speed - min_speed) // 2
            eating_time = self.eat_bananas(piles, middle)

            if eating_time <= h:
                max_speed = middle
            else:
                min_speed = middle + 1
        
        return min_speed
    
    def eat_bananas(self, piles, speed):
        time = 0

        for pile in piles:
            time += math.ceil(pile / speed)
        
        return time