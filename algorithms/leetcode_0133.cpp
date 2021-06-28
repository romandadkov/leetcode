/*
133. Clone Graph
https://leetcode.com/problems/clone-graph/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        Node* clone = helper(node, m);
        return clone;
    }
    
    Node* helper(Node* node, unordered_map<Node*, Node*> &m) {
        if(!node) {
            return nullptr;
        }
        
        if (m.count(node)) {
            return m[node];
        }
        
        Node* clone = new Node(node->val);
        m[node] = clone;
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(helper(neighbor, m));
        }
        
        return clone;
    }
};
