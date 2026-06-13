#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int left = 0;
        int right = matrix.size() * n - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            int value = matrix[middle / n][middle % n];

            if (value == target)
            {
                return true;
            }

            if (value < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        return false;
    }
};