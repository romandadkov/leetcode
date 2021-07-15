/*
154. Find Minimum in Rotated Sorted Array II
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
    
    int findMin(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        if (nums[left] < nums[right]) {
            return nums[left];
        }
        int mid = (right + left) / 2;
        return min(findMin(nums, left, mid), findMin(nums, mid + 1, right));
    }
};
