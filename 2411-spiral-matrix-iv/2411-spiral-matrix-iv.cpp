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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize matrix with -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        while (head) {
            // Traverse from left to right
            for (int col = left; col <= right && head; col++) {
                matrix[top][col] = head->val;
                head = head->next;
            }
            top++;
            
            // Traverse from top to bottom
            for (int row = top; row <= bottom && head; row++) {
                matrix[row][right] = head->val;
                head = head->next;
            }
            right--;
            
            // Traverse from right to left
            for (int col = right; col >= left && head; col--) {
                matrix[bottom][col] = head->val;
                head = head->next;
            }
            bottom--;
            
            // Traverse from bottom to top
            for (int row = bottom; row >= top && head; row--) {
                matrix[row][left] = head->val;
                head = head->next;
            }
            left++;
        }
        
        return matrix;
    }
};