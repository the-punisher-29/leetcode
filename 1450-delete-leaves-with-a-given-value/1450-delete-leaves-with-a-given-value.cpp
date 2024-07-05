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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;
        root->left = removeLeafNodes(root->left, target); 
        root->right = removeLeafNodes(root->right, target);
        // Check if the current node is a leaf node with the target value
        if (!root->left && !root->right && root->val == target) {
            return nullptr; // Delete the leaf node by returning nullptr
        }
        return root; // Return the current node (not a leaf node or not with target value)
    }
};