/*
143. Reorder List
https://leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }
        // fin the middle of the list
        ListNode *slow = head, *fast = head;
        for (; fast && fast->next;) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // cut the list ito two parts
        ListNode *mid = slow->next;
        slow->next = nullptr;
        // inverse 2nd part
        ListNode* p = nullptr;
        for (ListNode* t = mid; t;) {
            ListNode* next = t->next;
            t->next = p;
            p = t;
            t = next;
        }
        // merge
        for (ListNode* first = head, *second = p; first && second;) {
            ListNode* next = first->next;
            first->next = second;
            second = second->next;
            first->next->next = next;
            first = next;
        }
    }
};
