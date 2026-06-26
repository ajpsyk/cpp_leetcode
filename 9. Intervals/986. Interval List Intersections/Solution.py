from typing import List

class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        i = 0
        j = 0
        intersections = []

        while i < len(firstList) and j < len(secondList):
            start = firstList[i][0] if firstList[i][0] > secondList[j][0] else secondList[j][0]
            end = firstList[i][1] if firstList[i][1] < secondList[j][1] else secondList[j][1]

            if start <= end:
                intersections.append([start, end])
            
            if firstList[i][1] < secondList[j][1]:
                i += 1
            else:
                j += 1
        
        return intersections