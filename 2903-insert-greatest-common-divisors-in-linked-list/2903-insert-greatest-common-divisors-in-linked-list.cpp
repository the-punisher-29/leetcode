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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head; // If the list has 0 or 1 node, no insertion is needed
        ListNode* current = head;
        while (current && current->next) {
            int gcdValue = gcd(current->val, current->next->val);
            ListNode* newNode = new ListNode(gcdValue); // Create a new node with the GCD value
            newNode->next = current->next;              // Link new node to the next node
            current->next = newNode;                    // Link current node to new node
            current = newNode->next;                    // Move to the node after the newly inserted node
        }

        return head;
    }
};