from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:

        first_row_has_zero = False
        for col in range(len(matrix[0])):
            if matrix[0][col] == 0:
                first_row_has_zero = True
        
        first_col_has_zero = False
        for row in range(len(matrix)):
            if matrix[row][0] == 0:
                first_col_has_zero = True
        

        for row in range(1, len(matrix)):
            for col in range(1, len(matrix[0])):
                if matrix[row][col] == 0:
                    matrix[row][0] = 0
                    matrix[0][col] = 0
        
        for row in range(1, len(matrix)):
            for col in range(1, len(matrix[0])):
                if matrix[row][0] == 0 or matrix[0][col] == 0:
                    matrix[row][col] = 0
        
        if first_row_has_zero:
            for col in range(len(matrix[0])):
                matrix[0][col] = 0
        
        if first_col_has_zero:
            for row in range(len(matrix)):
                matrix[row][0] = 0
        