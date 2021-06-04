/*
86. Partition List
https://leetcode.com/problems/partition-list/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode left_head{-1};
        ListNode right_head{-1};
        
        ListNode* left = &left_head;
        ListNode* right = &right_head;
        
        ListNode* c = head;
        
        //split
        for (; c != nullptr; c = c->next) {
            if (c->val < x) {
                left->next = c;
                left = left->next;
            }
            else {
                right->next = c;
                right = right->next;
            }
        }
        
        right->next = nullptr;
        
        // merge
        left->next = right_head.next;
        
        return left_head.next;
    }
};

