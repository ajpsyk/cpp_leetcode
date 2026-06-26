from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        res = [intervals[0]]

        for i in range(1, len(intervals)):
            a = res[-1]
            b = intervals[i]

            if b[0] <= a[1]:
                res[-1] = [a[0], max(a[1], b[1])]
            else:
                res.append(b)
        
        return res
    