#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {

        bool first_row_has_zero = false;
        for (int col = 0; col < matrix[0].size(); ++col)
        {
            if (matrix[0][col] == 0) first_row_has_zero = true;
        }

        bool first_col_has_zero = false;
        for (int row = 0; row < matrix.size(); ++row)
        {
            if (matrix[row][0] == 0) first_col_has_zero = true;
        }


        for (int row = 1; row < matrix.size(); ++row)
        {
            for (int col = 1; col < matrix[0].size(); ++col)
            {
                if (matrix[row][col] == 0)
                {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        for (int row = 1; row < matrix.size(); ++row)
        {
            for (int col = 1; col < matrix[0].size(); ++col)
            {
                if (matrix[0][col] == 0 || matrix[row][0] == 0)
                {
                    matrix[row][col] = 0;
                }
            }
        }

        if (first_row_has_zero)
        {
            for (int col = 0; col < matrix[0].size(); ++col)
            {
                matrix[0][col] = 0;
            }
        }

        if (first_col_has_zero)
        {
            for (int row = 0; row < matrix.size(); ++row)
            {
                matrix[row][0] = 0;
            }
        }
    }
};