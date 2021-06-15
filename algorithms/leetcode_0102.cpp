/*
102. Binary Tree Level Order Traversal
https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> r;
        vector<TreeNode*> st;
        st.push_back(root);
        
        for (; st.size() != 0;) {
            vector<int> level;
            vector<TreeNode*> v;
            for (TreeNode* node : st) {
                addToQueue(v, node);
                level.push_back(node->val);
            }
            r.push_back(level);
            swap(st, v);
        }
        
        return r;
    }
    
    void addToQueue(vector<TreeNode*>& v, TreeNode* node) {
        if (node) {
            if (node->left) {
                v.push_back(node->left);
            }
            if (node->right) {
                v.push_back(node->right);
            }            
        }
    }
};
