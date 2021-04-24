/*
78. Subsets
https://leetcode.com/problems/subsets/
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int max = 1 << nums.size();
        for (int i = 0; i < max; ++i) {
            res.push_back(i_to_v(i, nums));
        }
        
        return res;
    }
    
    inline vector<int> i_to_v(int i, const vector<int>& nums) {
        vector<int> res;
        for (int j = 0; i > 0; i >>= 1, ++j) {
            if ((i & 1) == 1) {
                res.push_back(nums[j]);
            }
        }
        
        return res;
    }
};
