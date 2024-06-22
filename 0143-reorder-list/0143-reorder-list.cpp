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
        if (!head || !head->next)
            return;

        // Step 1: Find the middle of the linked list
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the linked list into two halves
        ListNode *middle = slow;
        ListNode *second_half = middle->next;
        middle->next = nullptr;

        // Step 2: Reverse the second half of the linked list
        ListNode *prev = nullptr;
        ListNode *current = second_half;
        while (current) {
            ListNode *next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        second_half = prev;

        // Step 3: Merge the first half and the reversed second half alternately
        ListNode *first_half = head;
        while (second_half) {
            ListNode *first_next = first_half->next;
            ListNode *second_next = second_half->next;
            first_half->next = second_half;
            second_half->next = first_next;
            first_half = first_next;
            second_half = second_next;
        }
    }
};