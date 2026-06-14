from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = [-1] * len(nums1)
        indexMap = {}
        stack = []

        for i in range(len(nums1)):
            indexMap[nums1[i]] = i

        for i in range(len(nums2) - 1, -1, -1):
            while stack and stack[-1] <= nums2[i]:
                stack.pop()

            if stack and nums2[i] in indexMap:
                res[indexMap[nums2[i]]] = stack[-1]
            
            stack.append(nums2[i])

        return res