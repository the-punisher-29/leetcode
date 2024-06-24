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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int diameter = 0;
        calculateDepth(root, diameter);
        
        return diameter;
    }

private:
    int calculateDepth(TreeNode* node, int& diameter) {
        if (node == nullptr) return 0;

        int leftDepth = calculateDepth(node->left, diameter);
        int rightDepth = calculateDepth(node->right, diameter);

        diameter = max(diameter, leftDepth + rightDepth);

        return 1 + max(leftDepth, rightDepth);
    }
};
