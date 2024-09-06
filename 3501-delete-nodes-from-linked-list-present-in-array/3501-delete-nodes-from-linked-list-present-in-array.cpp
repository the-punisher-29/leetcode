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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Dummy node to handle the case where the head needs to be removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            if (numSet.count(curr->val)) {
                // Remove the current node
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                // Move to the next node
                prev = curr;
                curr = curr->next;
            }
        }
        
        // The new head is the next of the dummy node
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};