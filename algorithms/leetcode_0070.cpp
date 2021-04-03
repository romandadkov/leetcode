/*
70. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/
*/

class Solution {
public:
/*
Dynamic Programming

problem can be broken into subproblems, and it contains the optimal substructure property i.e. its optimal solution can be constructed efficiently from optimal solutions of its subproblems, we can use dynamic programming to solve this problem.

One can reach i step in one of the two ways:
- Taking a single step from (i-1) step.
- Taking a step of 2 from (i-2) step.

The total number of ways to reach i step is equal to sum of ways of reaching (i-1) step and ways of reaching (i-2) step.
*/
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        
        std::vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};
