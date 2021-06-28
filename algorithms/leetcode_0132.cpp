/*
132. Palindrome Partitioning II
https://leetcode.com/problems/palindrome-partitioning-ii/
*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        // dp[i][j] indicates whether the substring in the range of [i, j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n));
        vector<int> dp_r(n);
        for (int i = n - 1; i >= 0; --i) {
            dp_r[i] = n - i - 1;
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    dp_r[i] = (j == n - 1) ? 0 : min(dp_r[i], dp_r[j + 1] + 1); 
                }
            }
        }
            
        return dp_r[0];
    }
};
