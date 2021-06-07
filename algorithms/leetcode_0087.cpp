/*
87. Scramble String
https://leetcode.com/problems/scramble-string/
*/

// dynamic programming approach 
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.empty() || s2.empty() || s1.size() != s2.size()) {
            return false;
        }
        
        int n = s1.size();
        if (s1.size() == 0) {
            return true;
        }
        
        /*
        A three-dimensional array dp[i][j][n] is used, where i is the starting character of s1, 
        j is the starting character of s2, and n is the current string length, dp[i][j][len] 
        indicates whether the string with length len starting from i and j 
        as s1 and s2 are scrambles for each other.
        */
        
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                for (int j = 0; j <= n - l; ++j) {
                    if (l == 1) {
                        dp[i][j][1] = s1[i] == s2[j];
                    }
                    else {
                        for (int k = 1; k < l; ++k) {
                            if ((dp[i][j][k] && dp[i + k][j + k][l - k]) ||
                                (dp[i + k][j][l - k] && dp[i][j + l - k][k])) {
                                dp[i][j][l] = true;
                            }
                        }
                    }
                }                    
            }
        }
        
        /*
        Dynamic programming space complexity is O(n^3)
        */
        
        return dp[0][0][n];
    }
};

/*
https://blog.csdn.net/linhuanmars/article/details/24506703
*/

