/*
148. Sort List
https://leetcode.com/problems/sort-list/
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        return merge(left, right);
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode *slow = nullptr, *fast = head;
        for (;fast && fast->next; fast = fast->next->next) {
            slow = (slow == nullptr) ? head : slow->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        return mid;
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode d = ListNode(-1);
        ListNode* ptr = &d;
        
        for (;left && right; ptr = ptr->next) {
            if (left->val < right->val) {
                ptr->next = left;
                left = left->next;
            }
            else {
                ptr->next = right;
                right = right->next;
            }
        }
        
        if (left) {
            ptr->next = left;
        }
        else {
            ptr->next = right;
        }
        
        return d.next;
    }
};
