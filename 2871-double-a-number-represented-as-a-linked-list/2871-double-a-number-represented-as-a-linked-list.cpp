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
    ListNode* doubleIt(ListNode* head) {
        // Step 1: Reverse the input list to make it easier to handle carry operations.
        head = reverse(head);
      
        // Create a dummy head to simplify the node insertion process.
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
      
        // Initialize multiplier to 2 for doubling the list values.
        const int multiplier = 2;
        int carry = 0; // To handle carry over during addition.

        // Step 2: Traverse the reversed list, doubling each node's value.
        while (head) {
            int product = head->val * multiplier + carry;
            carry = product / 10;
            current->next = new ListNode(product % 10);
            current = current->next;
            head = head->next; // Move to the next node.
        }

        // Step 3: If there's a carry after the last multiplication, add a new node for it.
        if (carry) {
            current->next = new ListNode(carry);
        }

        // Step 4: Reverse the list again to restore the original order.
        return reverse(dummy->next);
    }

    // Helper function to reverse a linked list.
    ListNode* reverse(ListNode* head) {
        // Create a dummy head to simplify the node insertion process.
        ListNode* dummy = new ListNode();
        ListNode* current = head;
      
        // Traverse the list and reverse the links.
        while (current) {
            ListNode* next = current->next; // Store next node.
            // Insert the current node at the beginning of the reversed list.
            current->next = dummy->next;
            dummy->next = current;
            // Move to the next node in the original list.
            current = next;
        }
        // Return the head of the reversed list.
        return dummy->next;
    }
};