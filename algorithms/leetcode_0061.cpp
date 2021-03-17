/*
61. Rotate List
https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        auto cur = head;
        size_t size = 0U;
        for (; cur->next != nullptr; ++size, cur = cur->next);
        ++size;
        k = k % size;
        
        for (; k != 0; --k) {
            auto p = head;
            for (auto i = 0; i < size - 1 - 1; ++i, p = p->next);
            auto a = p->next;
            p->next = nullptr;
            p = a->next;
            a->next = head;
            head = a;
        }
        
        return head;            
    }
};
