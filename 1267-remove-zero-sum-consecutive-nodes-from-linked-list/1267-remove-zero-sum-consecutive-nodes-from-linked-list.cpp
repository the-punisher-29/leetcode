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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        unordered_map<int, ListNode*> lastSeenPrefixSum;
        ListNode* current = dummyHead;
        int prefixSum = 0;

        while (current) {
            prefixSum += current->val;
            lastSeenPrefixSum[prefixSum] = current;
            current = current->next;
        }

        prefixSum = 0;
        current = dummyHead;

        while (current) {
            prefixSum += current->val;
            current->next = lastSeenPrefixSum[prefixSum]->next;
            current = current->next;
        }
        return dummyHead->next;
    }
};
