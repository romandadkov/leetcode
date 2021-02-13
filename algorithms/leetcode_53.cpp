/*
https://leetcode.com/problems/maximum-subarray/

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxCrossSum(vector<int>& nums, int l, int c, int r) {
        int l_s = 0;
        int prev_s = INT_MIN;
        for (int i = c; i >= l; --i) {
            l_s += nums[i];
            if (l_s > prev_s) prev_s = l_s;
        }
        l_s = prev_s;
        int r_s = 0;
        prev_s = INT_MIN;
        for (int i = c+1; i <= r; ++i) {
            r_s += nums[i];
            if (r_s > prev_s) prev_s = r_s;
        }
        r_s = prev_s;
        return l_s + r_s;
    }

    int maxSum(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int c = (l+r)/2;
        return std::max(std::max(maxSum(nums, l, c), maxSum(nums, c + 1, r)), maxCrossSum(nums, l, c, r));
    }
    
    int maxSubArray(vector<int>& nums) {
        return maxSum(nums, 0, nums.size() - 1);
    }
};
