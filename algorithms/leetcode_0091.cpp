/*
91. Decode Ways
https://leetcode.com/problems/decode-ways/
*/

// dynamic programming approach
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i < dp.size(); ++i) {
            /*
            Since s[1] is not 0, it can be split separately, which can be in the previous dp[i-1] 
            In each case, a single 2 is added, so that dp[i] can have at least as many splits as 
            dp[i-1]. Next, it depends on whether it can be combined with the previous number. 
            The two digits are less than or equal to 26 and greater than or equal to 10 (because 
            the high digit of the two digits cannot be 0), then you can add this two digit in each 
            case of dp[i-2], so In the end, dp[i] = dp[i-1] + dp[i-2],
            */
            dp[i] = s[i - 1] == '0' ? 0 : dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6') )) {
               dp[i] += dp[i - 2]; 
            }
        }
        
        return dp.back();
    }
};

