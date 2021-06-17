/*
113. Path Sum II
https://leetcode.com/problems/path-sum-ii/
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> r;
        vector<int> out;
        
        helper(root, targetSum, out, r);
        
        return r;
    }
    
    void helper(TreeNode* root, int targetSum, vector<int>& out, vector<vector<int>>& r) {
        if (!root) {
            return;
        }
        
        out.push_back(root->val);
        targetSum -= root->val;
        
        if (!root->left && !root->right && targetSum == 0) {
            r.push_back(out);
        }
        
        helper(root->left, targetSum, out, r);
        helper(root->right, targetSum, out, r);
        
        out.pop_back();
    }
};
