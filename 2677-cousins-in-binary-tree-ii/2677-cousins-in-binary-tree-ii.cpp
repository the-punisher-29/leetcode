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
//  */
// class Solution {
// public:
//     TreeNode* replaceValueInTree(TreeNode* root) {
//         if (!root) return nullptr;
        
//         // Use queue for level order traversal
//         queue<TreeNode*> q;
//         q.push(root);
//         root->val = 0;  // root has no cousins
        
//         while (!q.empty()) {
//             int levelSize = q.size();
//             unordered_map<TreeNode*, int> siblings;  // parent -> sibling sum
//             vector<TreeNode*> nextLevel;
            
//             // First pass: collect sibling sums
//             for (int i = 0; i < levelSize; i++) {
//                 TreeNode* curr = q.front();
//                 q.pop();
                
//                 // Calculate and store sibling sum for next level
//                 int childSum = 0;
//                 if (curr->left) {
//                     childSum += curr->left->val;
//                     nextLevel.push_back(curr->left);
//                 }
//                 if (curr->right) {
//                     childSum += curr->right->val;
//                     nextLevel.push_back(curr->right);
//                 }
//                 siblings[curr] = childSum;
//             }
            
//             // Calculate total sum of next level
//             int totalSum = 0;
//             for (auto& node : nextLevel) {
//                 totalSum += node->val;
//             }
            
//             // Update values for next level
//             for (auto& node : nextLevel) {
//                 TreeNode* parent = findParent(root, node);
//                 // cousins sum = total level sum - sibling sum (including the node itself)
//                 node->val = totalSum - siblings[parent];
//                 q.push(node);
//             }
//         }
        
//         return root;
//     }
    
// private:
//     TreeNode* findParent(TreeNode* root, TreeNode* target) {
//         if (!root) return nullptr;
//         if ((root->left == target) || (root->right == target)) return root;
        
//         TreeNode* left = findParent(root->left, target);
//         if (left) return left;
        
//         return findParent(root->right, target);
//     }
// };

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;
        
        // Use queue of {node, parent} pairs for level order traversal
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        root->val = 0;  // root has no cousins
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<pair<TreeNode*, TreeNode*>> currentLevel;
            
            // Collect nodes at current level with their parents
            for (int i = 0; i < levelSize; i++) {
                auto [node, parent] = q.front();
                q.pop();
                currentLevel.push_back({node, parent});
                
                // Add children to queue with their parent
                if (node->left) {
                    q.push({node->left, node});
                }
                if (node->right) {
                    q.push({node->right, node});
                }
            }
            
            // Calculate total sum of values at this level
            int totalSum = 0;
            for (auto& [node, _] : currentLevel) {
                totalSum += node->val;
            }
            
            // Group siblings by parent
            unordered_map<TreeNode*, int> parentSum;
            for (auto& [node, parent] : currentLevel) {
                parentSum[parent] += node->val;
            }
            
            // Update values
            for (auto& [node, parent] : currentLevel) {
                // New value is total sum minus sum of all nodes with same parent
                node->val = totalSum - parentSum[parent];
            }
        }
        
        return root;
    }
};