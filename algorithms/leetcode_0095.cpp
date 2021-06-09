/*
95. Unique Binary Search Trees II
https://leetcode.com/problems/unique-binary-search-trees-ii/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        
        vector<vector<vector<TreeNode*>>> memo(n, vector<vector<TreeNode*>>(n));
        
        return helper(memo, 1, n);
    }
    
    vector<TreeNode*> helper(vector<vector<vector<TreeNode*>>>& memo, int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        
        if (!memo[start - 1][end - 1].empty()) {
            return memo[start - 1][end - 1];
        }
        
        vector<TreeNode*> r;
        for (int i = start; i <= end; ++i) {
            auto left = helper(memo, start, i - 1);
            auto right = helper(memo, i + 1, end);
            for (auto a : left) {
                for (auto b : right) {
                    auto node = new TreeNode(i, a, b);
                    r.push_back(node);
                }
            }
        }
        
        memo[start - 1][end - 1] = r;
        
        return memo[start - 1][end - 1];
    }
};

