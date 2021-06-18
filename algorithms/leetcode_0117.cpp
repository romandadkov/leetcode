/*
117. Populating Next Right Pointers in Each Node II
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        if (root->right) {
            root->right->next = get_next(root);
        }
        
        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            }
            else {
                root->left->next = get_next(root);
            }
        }
        
        connect(root->right);
        connect(root->left);        
        
        return root;
    }
    
    
     Node* get_next(Node* root) {
         while (root->next) {
             if (root->next->left) {
                 return root->next->left;
             }
             else if (root->next->right) {
                 return root->next->right;
             }
             root = root->next;
         }
         
         return nullptr;
     }
};
