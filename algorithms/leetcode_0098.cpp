/*
98. Validate Binary Search Tree
https://leetcode.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
    bool isValidBST(TreeNode* root, long m, long n) {
        if (root == nullptr) {
            return true;
        }
        
        if (root->val <= m || root->val >= n) {
            return false;
        }
        
        return isValidBST(root->left, m, root->val) && isValidBST(root->right, root->val, n);
   }
};
