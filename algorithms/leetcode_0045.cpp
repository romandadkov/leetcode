/*
45. Jump Game II
https://leetcode.com/problems/jump-game-ii/
*/


class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty() || nums.size() < 2)
            return 0;
        int step = 0;
        int cur_max = 0;
        int next_max = 0;
        for (int i = 0; cur_max - i + 1 > 0;) {
            ++step;
            for (; i <= cur_max; ++i) {
                next_max = max(i + nums[i], next_max);
                if (next_max >= nums.size() - 1)
                    return step;
            }
            cur_max = next_max;
        }
        return 0;
    }
};