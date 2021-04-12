/*
73. Set Matrix Zeroes
https://leetcode.com/problems/set-matrix-zeroes/
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        
        const int row_count = matrix.size();
        const int col_count = matrix[0].size();
        bool row0_zero = false;
        bool col0_zero = false;
        
        for (int i = 0; i < row_count; ++i) {
            if (matrix[i][0] == 0) {
                col0_zero = true;
                break;
            }
        }
        
        for (int j = 0; j < col_count; ++j) {
            if (matrix[0][j] == 0) {
                row0_zero = true;
                break;
            }
        }
        
        
        for (int i = 1; i < row_count; ++i) {
            for (int j = 1; j < col_count; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < row_count; ++i) {
            bool is_zero_row = matrix[i][0] == 0;
            for (int j = 1; j < col_count; ++j) {
                if (is_zero_row || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (row0_zero) {
            for (int j = 0; j < col_count; ++j) {
                matrix[0][j] = 0;
            }
        }
        
        if (col0_zero) {
            for (int i = 0; i < row_count; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
