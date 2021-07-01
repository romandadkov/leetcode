/*
138. Copy List with Random Pointer
https://leetcode.com/problems/copy-list-with-random-pointer/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> m;
        Node* new_head = new Node(head->val);
        Node* p = new_head;
        m[head] = p;
        for (Node* c = head->next; c != nullptr; c = c->next) {
            Node* node = new Node(c->val);
            p->next = node;
            m[c] = node;
            p = p->next;
        }
        
        for (Node* node = new_head, *c = head; c != nullptr; node = node->next, c = c->next) {
            node->random = m[c->random];
        }
        
        
        return new_head;
    }
};
