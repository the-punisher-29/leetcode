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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};  // Less than 3 nodes, no critical points possible
        }
        
        vector<int> criticalPoints;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;
        int index = 1;
        
        while (next) {
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                criticalPoints.push_back(index);
            }
            
            prev = curr;
            curr = next;
            next = next->next;
            index++;
        }
        
        if (criticalPoints.size() < 2) {
            return {-1, -1};  // Less than 2 critical points
        }
        
        int minDistance = INT_MAX;
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i-1]);
        }
        
        int maxDistance = criticalPoints.back() - criticalPoints.front();
        
        return {minDistance, maxDistance};
    }
};