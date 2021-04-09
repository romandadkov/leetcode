/*
74. Search a 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        // start from up-right corner
        int row = 0;
        int col = matrix[0].size() - 1;
        //
        for (; row < matrix.size() && col >= 0;) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] > target) {
                // bottom-right side of matrix can be cut
                --col;
            }
            else {
                // up-left side of matrix can be cut
                ++row;
            }
        }
        
        return false;
    }
};
