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
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        
        // Use a queue for level-order traversal
        queue<TreeNode*> q;
        q.push(root);
        
        // Store level sums in a vector
        vector<long long> levelSums;
        
        // Perform level-order traversal
        while (!q.empty()) {
            int size = q.size();
            long long levelSum = 0;
            
            // Process all nodes at current level
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                levelSum += curr->val;
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            
            levelSums.push_back(levelSum);
        }
        
        // If we have fewer levels than k, return -1
        if (levelSums.size() < k) {
            return -1;
        }
        
        // Sort the level sums in descending order
        sort(levelSums.begin(), levelSums.end(), greater<long long>());
        
        // Return the kth largest level sum
        return levelSums[k - 1];
    }
};