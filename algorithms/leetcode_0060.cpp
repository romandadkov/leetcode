/*
60. Permutation Sequence
https://leetcode.com/problems/permutation-sequence/
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        std::iota(begin(nums), end(nums), 1);
        const auto total = accumulate(begin(nums), end(nums), 1, multiplies<int>());
        
        if (k > total) {
            return "";
        }
        
        // Construct the k-th permutation with a list of n numbers
        // Idea: group all permutations according to their first number (so n groups, each of
        // (n-1)! numbers), find the group where the k-th permutation belongs, remove the common
        // first number from the list and append it to the resulting string, and iteratively
        // construct the (((k-1)%(n-1)!)+1)-th permutation with the remaining n-1 numbers
        
        stringstream ss;
        for (auto group = total; n > 0; --n) {
            group = group / n;
            const auto idx = (k - 1) / group;
            ss << nums[idx];
            nums.erase(begin(nums) + idx);
            //the next k also can be caculated like this: 
            //    k = (k-1)%group + 1; 
            k -= group * idx;
        }
        
        return ss.str();
    }
};
