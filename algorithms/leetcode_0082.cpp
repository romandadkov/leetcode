/*
82. Remove Duplicates from Sorted List II
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
        ListNode n{-1};
        ListNode* b = &n;
        b->next = head;
        ListNode* p = b;
        
        for (; p->next;) {
            ListNode* c = p->next;
            for (; c->next &&  c->next->val ==  c->val; c = c->next);
            if (c != p->next) p->next = c->next;
            else p = p->next;
        }
        
        return b->next;
    }
};