/*
131. Palindrome Partitioning
https://leetcode.com/problems/palindrome-partitioning/
*/

// recursion
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> r;
        vector<string> out;
        helper(s, 0, r, out);
        return r;
    }
    
    void helper(string s, int p, vector<vector<string>>& r, vector<string>& out) {
        if (p == s.size()) {
            r.push_back(out);
        }
        for (int i = p; i < s.size(); ++i) {
            if (isPalindrome(s, p, i)) {
                out.push_back(s.substr(p, i - p + 1));
                helper(s, i + 1, r, out);
                out.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start; --end;
        }
        return true;
    }
};

// dynamic programming
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> r;
        vector<string> out;
        int n = s.size();
        // dp[i][j] indicates whether the substring in the range of [i, j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                }
            }
        }
        
        helper(s, 0, dp, r, out);
            
        return r;
    }
    
    void helper(string s, int p, vector<vector<bool>>& dp, vector<vector<string>>& r, vector<string>& out) {
        if (p == s.size()) {
            r.push_back(out);
        }
        for (int i = p; i < s.size(); ++i) {
            if (dp[p][i]) {
                out.push_back(s.substr(p, i - p + 1));
                helper(s, i + 1, dp, r, out);
                out.pop_back();
            }
        }
    }
};
