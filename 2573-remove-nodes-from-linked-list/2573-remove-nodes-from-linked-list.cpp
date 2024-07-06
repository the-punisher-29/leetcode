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
    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        if (!head) return nullptr;
        
        // Step 1: Reverse the linked list
        ListNode* reversedHead = reverseList(head);
        
        // Step 2: Traverse the reversed list and remove nodes
        ListNode* curr = reversedHead;
        ListNode* maxNode = reversedHead;
        
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->val < maxNode->val) {
                // Remove the next node
                curr->next = curr->next->next;
            } else {
                // Update maxNode and move to next
                curr = curr->next;
                maxNode = curr;
            }
        }
        
        // Step 3: Reverse the list again to restore original order
        return reverseList(reversedHead);
    }
};