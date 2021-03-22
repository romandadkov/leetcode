/*
63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) {
        	return 0;
        }
        
        const int n = obstacleGrid.size();
        const int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n + 1, vector(m + 1, 0));
        dp[0][1] = 1;
        for (int row = 1; row <= n; ++row) {
            for (int col = 1; col <= m; ++col) {
                if (obstacleGrid[row-1][col-1] == 0) {
                    dp[row][col] = dp[row-1][col] + dp[row][col - 1];
                }
            }
        }            
        return dp[n][m];
    }
};
