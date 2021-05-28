/*
43. Multiply Strings
https://leetcode.com/problems/multiply-strings/
*/
class Solution {
public:
    string str_plus(string num1, string num2) {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;

        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }
        string ans;
        int carry = 0;
        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; --i, --j) {
            int a1 = num1[i] - '0';            
            int a = a1 + carry;
            if (j >= 0) {
                a += num2[j] - '0';
            }
            carry = a / 10;
            ans.insert(ans.begin(), (a % 10) + '0');
        }
        
        if (carry) {
            ans.insert(ans.begin(), carry + '0');
        }
        
        return ans;
    }
    
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()){ 
            return "";
        }

        string ans;
        for (int i = num1.size() - 1; i >= 0; --i) {
            int carry = 0;
            string val;
            for (int j = num2.size() - 1; j >= 0; --j) {
                int v = (num2[j] - '0') * (num1[i] - '0') + carry;
                carry = v / 10;
                val.insert(val.begin(), v % 10 + '0');
            }

            if (carry) {
                val.insert(val.begin(), carry + '0');
            }
            
            for (auto j = i; j < num1.size() - 1; ++j) {
                val.push_back('0');
            }
            
            ans = str_plus(ans, val);
        }
        
        if (ans[0] == '0') {
            return "0";
        }
        
        return ans;
    }
};