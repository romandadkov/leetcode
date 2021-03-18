/*
62. Unique Paths
https://leetcode.com/problems/unique-paths/
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector(m, 1));
        for (int row = 1; row < n; ++row) {
            for (int col = 1; col < m; ++col) {
                dp[row][col] = dp[row-1][col] + dp[row][col - 1];
            }
        }            
        return dp[n-1][m-1];
    }
};

// https://blog.csdn.net/linhuanmars/article/details/22126357
