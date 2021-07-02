/*
141. Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        for (ListNode *slow = head, *fast = head; fast != nullptr && fast->next != nullptr;) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
    /*
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        for (ListNode* n = head; n; n = n->next) {
            if (s.count(n)) {
                return true;
            }
            s.insert(n);
        }
        return false;
    }
    */
};
