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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Advance first pointer so that the gap between first and second is n nodes apart
        for (int i = 0; i <= n; ++i) {
             if (first == nullptr)
                  return nullptr; // n is greater than the number of nodes in the list
            first = first->next;
        }

         // Move first to the end, maintaining the gap
         while (first != nullptr) {
             first = first->next;
             second = second->next;
        }

         // Remove the nth node from the end
         ListNode* temp = second->next;
         second->next = second->next->next;
         delete temp;

         return dummy->next;
         }
};