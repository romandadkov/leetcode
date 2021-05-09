/*
46. Permutations
https://leetcode.com/problems/permutations/

Backtracking is an algorithm for finding all solutions by exploring all potential candidates. If the solution candidate turns to be not a solution (or at least not the last one), backtracking algorithm discards it by making some changes on the previous step, i.e. backtracks and then try again.

Here is a backtrack function which takes the index of the first integer to consider as an argument backtrack(first).

If the first integer to consider has index n that means that the current permutation is done.
Iterate over the integers from index first to index n - 1.
Place i-th integer first in the permutation, i.e. swap(nums[first], nums[i]).
Proceed to create all permutations which starts from i-th integer : backtrack(first + 1).
Now backtrack, i.e. swap(nums[first], nums[i]) back.
*/
class Solution {
    vector<vector<int>> ans;
public:
    void permute_helper(vector<int>& nums, int l, int r) {
        if (l == r)
            ans.push_back(nums);
        else
            for (int i = l; i <= r; ++i)
            {
                swap(nums[l], nums[i]);
                permute_helper(nums, l + 1, r);
                swap(nums[l], nums[i]);
            }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permute_helper(nums, 0, nums.size() - 1);
        return ans;
    }
};