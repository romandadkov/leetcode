/*
123. Best Time to Buy and Sell Stock III
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        // dynamic programming solution
        const int n = prices.size();
        /*
         local optimum 
         maximum profit that can be made at most j transactions when 
         the i-th day is reached and the last transaction is sold 
         on the last day
        */
        vector<vector<int>> l(n, vector<int>(3));
        /*
        global optimum
        maximum profit that can be performed at most j transactions
        when the i-th day is reached
        */
        vector<vector<int>> g(n, vector<int>(3));
        
        for (int i = 1; i < n; ++i) {
            int d = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) {
                l[i][j] = max(g[i-1][j-1] + max(d, 0), l[i-1][j] + d);
                g[i][j] = max(l[i][j], g[i-1][j]);
            }
        }
        
        return g[n-1][2];
    }
};
