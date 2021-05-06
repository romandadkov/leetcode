/*
47. Permutations II
https://leetcode.com/problems/permutations-ii/

Given a collection of numbers that might contain duplicates, return all possible unique permutations.
*/

class Solution {
    
    struct custom_hash {
    size_t operator()(const vector<int>& v) const {
            hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    unordered_set<vector<int>, custom_hash> ans;

    void permute_helper(vector<int>& nums, int l, int r) {
        if (l == r)
            ans.insert(nums);
        else
        {
            for (int i = l; i <= r; ++i)
            {
                swap(nums[l], nums[i]);
                permute_helper(nums, l + 1, r);
                swap(nums[l], nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permute_helper(nums, 0, nums.size() - 1);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};