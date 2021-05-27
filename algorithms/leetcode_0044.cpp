/*
44. Wildcard Matching
https://leetcode.com/problems/wildcard-matching/
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p == "*") {
            return true;
        }
        int j = 0;
        for (int i = 0, k = 0, p_star = 0; i < s.size();) {
            if (s[i] == p[j] || p[j] == '?') {
                ++i;
                ++j;
            }
            else if (p[j] == '*') {
                ++j;
                if (j == p.size()) {
                    return true;
                }
                k = s.size() - i - 1;
                p_star = j;
            }
            else if (k) {
                --k;
                i = s.size() - k - 1;
                j = p_star;
            }
            else {
                return false;
            }
        }
        for (; j < p.size() && p[j] == '*'; ++j) {}
        return j == p.size();
    }
};