/*
72. Edit Distance
https://leetcode.com/problems/edit-distance/
*/

class Solution {
  public:
    int minDistance(string word1, string word2) {
        const int n = word1.size() + 1;
        const int m = word2.size() + 1;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; dp[i][0] = i, ++i);
        for (int j = 0; j < m; dp[0][j] = j, ++j);

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};

// dynamic programming approach

// example:
//   Ø a b c d
// Ø 0 1 2 3 4
// b 1 1 1 2 3
// b 2 2 1 2 3
// c 3 3 2 1 2

// pseudo code:
// dp[i][j] := dp[i - 1][j - 1] if (word1[i - 1] == word2[j - 1]) else (min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1)

