/*
106. Construct Binary Tree from Inorder and Postorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr) {
        if (il > ir || pl > pr) {
            return nullptr;
        }
        
        int i = il;
        for (; i <= ir; ++i) {
            if (inorder[i] == postorder[pr]) {
                break;
            }
        }
        
        TreeNode* node = new TreeNode(postorder[pr]);
        /**
        (i - il) since counting above started from il
        */ 
        node->left = buildTree(inorder, il, i - 1, postorder, pl, pl + (i - il) - 1);
        node->right = buildTree(inorder, i + 1, ir, postorder, pl + (i - il), pr - 1);
        
        return node;
    }
        
};
