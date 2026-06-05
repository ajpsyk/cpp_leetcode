from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_sets = [set() for _ in range(9)]
        col_sets = [set() for _ in range(9)]
        box_sets = [[set() for _ in range(3)] for _ in range(3)]

        for row in range(9):
            for col in range(9):
                val = board[row][col]

                if val == '.':
                    continue
                
                if val in row_sets[row]:
                    return False
                
                if val in col_sets[col]:
                    return False
                
                if val in box_sets[row // 3][col // 3]:
                    return False

                row_sets[row].add(val)
                col_sets[col].add(val)
                box_sets[row // 3][col // 3].add(val)
        
        return True
