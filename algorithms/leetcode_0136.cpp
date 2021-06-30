/*
136. Single Number
https://leetcode.com/problems/single-number/
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r = 0;
        for (const int num : nums) {
            r ^= num;
        }
        return r;
        /*
        unordered_set<int> s;
        for (const int num : nums) {
            if (s.count(num) == 0) {
                s.insert(num);
            }
            else {
                s.erase(num);
            }
        }
        
        return *s.begin();
        */
    }
};
