/*
156. Binary Tree Upside Down
https://leetcode.com/problems/binary-tree-upside-down/
*/

class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if (!root || !root->left) {
			return root; 
		}
		
		TreeNode *left = root->left;
		TreeNode *right = root->right;
		TreeNode *t = upsideDownBinaryTree(left);
		
		// left becomes root, right becomes left node
		left->left = right;
		// original root becomes right node
		left->right = root;
		root->left = nullptr;
		root->right = nullptr;
		
		return t;
    }
};
