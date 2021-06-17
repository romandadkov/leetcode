/*
115. Distinct Subsequences
https://leetcode.com/problems/distinct-subsequences/
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<ulong>> dp(n + 1, vector<ulong>(m + 1));
        
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        
        return dp[n][m];
    }
};
