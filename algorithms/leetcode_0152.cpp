/*
152. Maximum Product Subarray
https://leetcode.com/problems/maximum-product-subarray/
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int r = nums[0];
        const int n = nums.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);
        f[0] = g[0] = r;
        for (int i = 1; i < n; ++i) {
            f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
            g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
            r = max(r, f[i]);
        }
        
        return r;
    }
};
