/*
101. Symmetric Tree
https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isSameTree(root->left, root->right);
    }
    
     bool isSameTree(TreeNode* p, TreeNode* q) {
         if (!p && !q) {
             return true;
         }
         if ((!p && q) || (p && !q) || (p->val != q->val)) {
             return false;
         }
         return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
     }
};
