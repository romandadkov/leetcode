/*
105. Construct Binary Tree from Preorder and Inorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        if (pl > pr || il > ir) {
            return nullptr;
        }
        
        int i = il;
        for (; i <= ir; ++i) {
            if (preorder[pl] == inorder[i]) {
                break;
            }
        }
        
        TreeNode* node = new TreeNode(inorder[i]);
        node->left = buildTree(preorder, pl + 1, pl + i - il, inorder, il, i - 1);
        node->right = buildTree(preorder, pl + i - il + 1, pr, inorder, i + 1, ir);
        
        return node;
    }
};
