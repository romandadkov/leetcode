/*
96. Unique Binary Search Trees
https://leetcode.com/problems/unique-binary-search-trees/
*/

class Solution {
public:
    int numTrees(int n) {
        if (n == 0) {
            return 0;
        }
        
        vector<vector<int>> memo(n, vector<int>(n));
        return helper(memo, 1, n);
    }
    
    int helper(vector<vector<int>>& memo, int start, int end) {
        if (start > end) {
            return 1;
        }

        if (memo[start - 1][end - 1] != 0) {
            return memo[start - 1][end - 1];
        }
        
        int r{0};
        
        for (int i = start; i <= end; ++i) {
            auto left = helper(memo, start, i - 1);
            auto right = helper(memo, i + 1, end);
            r += left * right;
        }
        
        memo[start - 1][end - 1] = r;
        
        return memo[start - 1][end - 1];
    }
    /*
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        
        return dp[n];
    }
    */
};

