/*
65. Valid Number
https://leetcode.com/problems/valid-number/
*/

class Solution {
public:
    bool isNumber(string s) {
        bool num = false, num_after_e = true, dot = false, exp = false, sign = false;
        for (int i = 0, n = s.size(); i < n; ++i) {
            if (s[i] == ' ') {
                if (i < n - 1 && s[i + 1] != ' ' && (num || dot || exp || sign)) {
                    return false;
                }
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') {
                    return false;
                }
                sign = true;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                num = true;
                num_after_e = true;
            }
            else if (s[i] == '.') {
                if (dot || exp) {
                    return false;
                }
                dot = true;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                if (exp || !num) {
                    return false;
                }
                exp = true;
                num_after_e = false;
            }
            else {
                return false;
            }
        }
        
        return num && num_after_e;
    }
};
