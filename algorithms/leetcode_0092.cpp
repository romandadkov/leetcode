/*
92. Reverse Linked List II
https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode knode(-1);
        ListNode* k = &knode;
        k->next = head;
        ListNode* p = k;
        
        int i = 0;
        for (; i < left - 1; ++i) {
            p = p->next;
        }
        ListNode* c = p->next;
        for (i = left; i < right; ++i) {
            ListNode* t = c->next;
            c->next = t->next;
            t->next = p->next;
            p->next = t;
        }
        
        
        return k->next;
    }
};

