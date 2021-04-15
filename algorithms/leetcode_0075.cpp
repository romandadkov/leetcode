/*
75. Sort Colors
https://leetcode.com/problems/sort-colors/
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int right = nums.size() - 1, left = 0, i = 0;
        for (; i <= right;) {
            if (nums[i] == 0) {
                swap(nums[left++], nums[i++]);
            }
            else if (nums[i] == 2) {
                swap(nums[right--], nums[i]);
            }
            else {
                ++i;
            }
        } 
    }
};

