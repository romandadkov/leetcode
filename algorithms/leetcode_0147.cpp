/*
147. Insertion Sort List
https://leetcode.com/problems/insertion-sort-list/
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* a = new ListNode(-1);
        for (ListNode* cur = a; head;) {
            ListNode* t = head->next;
            
            for (cur = a; cur->next && cur->next->val < head->val; cur = cur->next);
            
            head->next = cur->next;
            cur->next = head;
            
            head = t;
        }
        
        return a->next;
    }
};
