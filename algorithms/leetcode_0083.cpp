/*
83. Remove Duplicates from Sorted List
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        ListNode* c = head;
        
        for (; c != nullptr; c = c->next) {
            /*
            if (p->val == c->val && c->next == nullptr) {
                p->next = nullptr;
            }
            else */
            // which is the same
            p->next = c->next;
            if (p->val != c->val) {
                p->next = c;
                p = c;
            }
        }
        
        return head;
    }
};
