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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }
        int base_size = length / k;
        int extra = length % k;
        
        vector<ListNode*> result(k, nullptr);
        current = head;
        for (int i = 0; i < k && current; i++) {
            result[i] = current;
            int part_size = base_size + (i < extra ? 1 : 0);
            for (int j = 0; j < part_size - 1; j++) {
                current = current->next;
            }
            ListNode* next = current->next;
            current->next = nullptr;
            current = next;
        }
        return result;
    }
};