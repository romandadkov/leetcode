/*
100. Same Tree
https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;
        for (; p || q || !st.empty(); p = p->right, q = q->right) {
            for(; p || q; st.push(p), st.push(q), p = p->left, q = q->left) {
               if ((!p && q) || (p && !q) || (p->val != q->val)) {
                   return false;
               }
            }
            
            p = st.top(); st.pop();
            q = st.top(); st.pop();
        }
        
        return true;
    }
};
