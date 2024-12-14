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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (!check) return head;  // Not enough nodes to reverse
            check = check->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Recursively reversing next k-group
        // head is now the last node of the reversed group
        head->next = reverseKGroup(curr, k);
        // prev is the new head of this k-group
        return prev;
    }
};