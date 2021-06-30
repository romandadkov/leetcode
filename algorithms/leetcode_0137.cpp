/*
137. Single Number II
https://leetcode.com/problems/single-number-ii/
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        ab
        00 + 1 = 01
        01 + 1 = 10
        10 + 1 = 00 ( mod 3)
        */
        int a = 0, b = 0;
        for (const int num : nums) {
            b = (b ^ num) & ~a;
            a = (a ^ num) & ~b;
        }
        return b;
        /*
        unordered_multiset<int> s;
        for (const int num : nums) {
            if (s.count(num) == 2) {
                s.erase(num);
                continue;
            }
            s.insert(num);
        }
        
        return *s.begin();
        */
    }
};
