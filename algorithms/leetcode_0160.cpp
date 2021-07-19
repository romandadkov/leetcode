/*
160. Intersection of Two Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

/**
 Although the title emphasizes that there is no ring in the linked list, 
 we can use the idea of ​​ring to do it. We let the two linked lists start 
 from the beginning of each and traverse backward. When one of them 
 traversing to the end, we jump to the beginning of another linked list 
 to continue traversing. The two pointers will eventually be equal, and 
 there are only two cases, one is when they meet at the intersection, 
 and the other is when they are equal at the empty node at the end. 
 Why must they be equal? ​​Because the distance traveled by the two pointers 
 is the same, which is the sum of the lengths of the two linked lists, 
 they must be equal.
 */
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode * a = headA;
        ListNode * b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        
        return a;
    }
};
