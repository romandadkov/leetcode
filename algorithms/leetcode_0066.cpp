/*
66. Plus One
https://leetcode.com/problems/plus-one/
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return digits;
        }
        
        int one = 1;
        for (int i = digits.size() -1; i >= 0 && one == 1; --i) {
            auto a = digits[i] + one;
            digits[i] = a % 10;
            one = a / 10;
        }
        
        if (one == 1) {
            digits.insert(begin(digits), one);
        }
        
        return digits;
    }
};
