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
    ListNode* deleteMiddle(ListNode* head) {
        // If the list is empty or has only one node
        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }
        
        // Use two pointers: slow and fast
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        // Move fast pointer twice as fast as slow pointer
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        // Delete the middle node
        prev->next = slow->next;
        delete slow;
        
        return head;
    }
};