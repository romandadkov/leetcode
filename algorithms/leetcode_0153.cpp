/*
153. Find Minimum in Rotated Sorted Array
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        const int n = nums.size() - 1;
        return findMin(nums, 0, n);
    }
             
    int findMin(vector<int>& nums, const int left, const int right) {
        if (nums[left] <= nums[right]) {
            return min(nums[left], nums[right]);
        }
        const int mid = (right + left) / 2;
        return min(findMin(nums, left, mid), findMin(nums, mid + 1, right));
    }
};
