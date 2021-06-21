/*
121. Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = numeric_limits<int>::max(), r = 0;
        for (const auto& price : prices) {
            buy = min(buy, price);
            r = max(r, price - buy);
        }
        
        return r;
    }
};
