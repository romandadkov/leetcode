/*
90. Subsets II
https://leetcode.com/problems/subsets-ii/
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> r;
        vector<int> st;
        
        subsets(nums, r, 0, st);
        
        return r;
    }
    
    void subsets(vector<int>& nums, vector<vector<int>>& r, int p, vector<int>& st) {
        r.push_back(st);
        for (int i = p; i < nums.size(); ++i) {
            st.push_back(nums[i]);
            subsets(nums, r, i + 1, st);
            st.pop_back();
            for (; i + 1 < nums.size() && nums[i] == nums[i + 1]; ++i);
        }
    }
};

