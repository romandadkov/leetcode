/*
124. Binary Tree Maximum Path Sum
https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode* root) {
        int r = numeric_limits<int>::min();
        helper(root, r);
        return r;
    }
    
    int helper(TreeNode* root, int& r) {
        if (!root) {
            return 0;
        }
        
        auto left = max(helper(root->left, r), 0);
        auto right = max(helper(root->right, r), 0);
        r = max(r, left + right + root->val);
        
        return max(left, right) + root->val;
    }
};
