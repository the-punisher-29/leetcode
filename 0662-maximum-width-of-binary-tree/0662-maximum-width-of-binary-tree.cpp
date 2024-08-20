/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 //TC-O(N) and SC-O(N)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            long long minIndex = q.front().second;
            long long leftIndex, rightIndex;
            
            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();
                
                if (i == 0) leftIndex = index;
                if (i == size - 1) rightIndex = index;
                
                if (node->left) q.push({node->left, 2 * (index - minIndex)});
                if (node->right) q.push({node->right, 2 * (index - minIndex) + 1});
            }
            
            maxWidth = max(maxWidth, (int)(rightIndex - leftIndex + 1));
        }
        
        return maxWidth;
    }
};