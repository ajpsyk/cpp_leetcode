#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::unordered_set<char>> row_sets(9);
        std::vector<std::unordered_set<char>> col_sets(9);
        std::vector<std::vector<std::unordered_set<char>>> box_sets(3, std::vector<std::unordered_set<char>>(3));

        for(int row = 0; row < 9; ++row)
        {
            for(int col = 0; col < 9; ++col)
            {
                char val = board[row][col];

                if (val == '.') continue;
                if (row_sets[row].count(val)) return false;
                if (col_sets[col].count(val)) return false;
                if (box_sets[row / 3][col / 3].count(val)) return false;

                row_sets[row].insert(val);
                col_sets[col].insert(val);
                box_sets[row / 3][col / 3].insert(val);
            }
        }
        return true;
    }
};