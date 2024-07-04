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
    ListNode* mergeNodes(ListNode* head) {
        if (!head || !head->next) { // Base case: empty or single-node list
            return head;
        }

        ListNode* dummy = new ListNode(0);  // Dummy node to simplify head handling
        ListNode* prev = dummy;             // Pointer to track the previous merged node

        ListNode* current = head;
        int currentSum = 0; 

        while (current != nullptr) {
            if (current->val == 0) {         // Found a zero
                if (currentSum > 0) {       // If nodes were merged
                    prev->next = new ListNode(currentSum); // Create new merged node
                    prev = prev->next; 
                    currentSum = 0;          // Reset for the next merge
                }
            } else {
                currentSum += current->val;  // Accumulate values between zeros
            }
            current = current->next;         // Move to the next node
        }

        return dummy->next;                   // Return head of the modified list
    }
};