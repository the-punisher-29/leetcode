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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        
        while (ptrA != ptrB) {
            // Move to the next node, or to the head of the other list if reached end
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }
        
        return ptrA; // At this point, ptrA and ptrB are either both null or at the intersection
    }
};