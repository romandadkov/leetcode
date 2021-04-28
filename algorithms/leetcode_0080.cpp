/*
80. Remove Duplicates from Sorted Array II
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int n = nums.size();
        bool f = false;
        for (int i = 0, j = 1; i < n && j < n;) {
            if (nums[i] == nums[j] && f) {
                nums.erase(nums.begin() + j);
                --n;
            }
            else if (nums[i] == nums[j] && !f) {
                f = true;
                ++i;
                ++j;
            }
            else {
                f = false;
                i = j;
                ++j;
            }
        }
        
        return nums.size();
    }
};
