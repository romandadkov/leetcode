/*
93. Restore IP Addresses
https://leetcode.com/problems/restore-ip-addresses/
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        
        helper(r, s, "", 0);
        
        return r;
    }
    
    void helper(vector<string>& r, string s, string cur, int n) {
        if (n == 4) {
            if (s.empty()) {
                r.push_back(cur);
            }
        }
        else {
            for (int i = 1; i <= 3 && i <= s.size(); ++i) {
                const string s1 = s.substr(0, i);
                const string s2 = s.substr(i);
                if (is_valid(s1, i)) {
                    helper(r, s2, cur + s1 + (n == 3 ? "" : "."), n + 1);
                }
            }
        }
    }
    
    bool is_valid(const string& s, const int len) {
        const int a = stoi(s);
        const int b = std::to_string(a).size(); 
        return (a <= 255) && (b == len);
    }
};

