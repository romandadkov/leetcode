/*
64. Minimum Path Sum
https://leetcode.com/problems/minimum-path-sum/
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid.at(0).empty()) {
            return 0;
        }
        
        auto const rows = grid.size();
        auto const cols = grid.at(0).size();
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (row == 0 && col == 0) {
                    continue;
                }
                if (row == 0) {
                    grid[row][col] += grid[row][col - 1];
                }
                else if (col == 0) {
                    grid[row][col] += grid[row - 1][col];
                }
                else {
                    grid[row][col] += min(grid[row][col - 1], grid[row - 1][col]);
                }
            }
        }
        
        return grid.back().back();
    }
};
