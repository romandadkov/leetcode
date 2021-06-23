/*
128. Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence/
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s{nums.begin(), nums.end()};
        int r = 0;
        for (auto num: nums) {
            if (!s.count(num)) {
                continue;
            }
            
            s.erase(num);
            
            auto n1 = num - 1;
            auto n2 = num + 1;
            while (s.count(n1)) {
                s.erase(n1);
                --n1;
            }
            while (s.count(n2)) {
                s.erase(n2);
                ++n2;
            }
            
            r = max(r, n2 - n1 - 1);
        }
        
        return r;
    }
};
