from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums2) < len(nums1):
            nums1, nums2 = nums2, nums1

        m = len(nums1)
        n = len(nums2)
        half_total = (m + n) // 2

        left = 0
        right = len(nums1) - 1

        while True:
            L1_index = left + (right - left) // 2
            L2_index = half_total - (L1_index + 1) - 1

            L1 = float('-inf') if L1_index < 0 else nums1[L1_index]
            R1 = float('inf') if L1_index + 1 > m - 1 else nums1[L1_index + 1]
            L2 = float('-inf') if L2_index < 0 else nums2[L2_index] 
            R2 = float('inf') if L2_index + 1 > n - 1 else nums2[L2_index + 1]

            if L1 > R2:
                right = L1_index - 1
            elif L2 > R1:
                left = L1_index + 1
            else:
                if (m + n) % 2 == 0:
                    return (max(L1, L2) + min(R1, R2)) / 2
                else:
                    return min(R1, R2)
