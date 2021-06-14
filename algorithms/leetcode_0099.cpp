/*
99. Recover Binary Search Tree
https://leetcode.com/problems/recover-binary-search-tree/
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
    void recoverTree(TreeNode* root) {
        TreeNode *pre = nullptr, *a = nullptr, *b = nullptr, *p = root;
        stack<TreeNode*> st;
        for (; p || !st.empty(); pre = p, p = p->right) {
            for (; p != nullptr ; st.push(p), p = p->left);
            p = st.top();
            st.pop();
            if (pre) {
                if (pre->val > p->val) {
                    if (a == nullptr) {
                        a = pre;
                    }
                    b = p;
                }
            }
        }
        swap(a->val, b->val);
    }
};
