/*
122. Best Time to Buy and Sell Stock II
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int r = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                r += prices[i + 1] - prices[i];
            }
        }
        
        return r;
    }
};
