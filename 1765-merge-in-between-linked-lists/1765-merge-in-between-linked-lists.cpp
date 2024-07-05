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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prev_a = nullptr, *prev_b = nullptr, *temp = list1;
        
        // Find the ath and (b+1)th nodes
        for (int i = 0; i < b + 1; ++i) {
            if (i == a - 1) prev_a = temp;
            if (i == b) prev_b = temp;
            temp = temp->next;
        }
        
        // Connect the prev_a node to the start of list2
        prev_a->next = list2;
        
        // Find the end of list2
        temp = list2;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        // Connect the end of list2 to the node after prev_b
        temp->next = prev_b->next;
        
        // Delete the nodes from a to b
        prev_b->next = nullptr;
        
        return list1;
    }
};