#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums2.size() < nums1.size()) std::swap(nums1, nums2);
        int m = nums1.size();
        int n = nums2.size();
        int halfSize = (m + n) / 2;

        int left = 0;
        int right = m - 1;

        while (true)
        {
            int leftIndex1 = (right + left < 0) ? -1 : (right + left) / 2;
            int leftIndex2 = halfSize - (leftIndex1 + 1) - 1;

            double left1 = (leftIndex1 < 0) ? -INFINITY : nums1[leftIndex1];
            double right1 = (leftIndex1 + 1 > m - 1) ? INFINITY : nums1[leftIndex1 + 1];
            double left2 = (leftIndex2 < 0) ? -INFINITY : nums2[leftIndex2];
            double right2 = (leftIndex2 + 1 > n - 1) ? INFINITY : nums2[leftIndex2 + 1];

            if (left1 > right2)
            {
                right = leftIndex1 - 1;
            }
            else if (left2 > right1)
            {
                left = leftIndex1 + 1;
            }
            else
            {
                if ((m + n) % 2 == 0)
                {
                    return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
                }
                else
                {
                    return std::min(right1, right2);
                }
            } 
        }
    }
};