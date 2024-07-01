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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* nR = new TreeNode(val);
            nR->left = root;
            return nR;
        }
        adder(root, val, depth, 1);
        return root;
    }

private:
    void adder(TreeNode* node, int val, int depth, int currentDepth) {
        if (!node) {
            return ;
        }
        if (currentDepth == depth - 1) {
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            newLeft->left = node->left;
            newRight->right = node->right;
            node->left = newLeft;
            node->right = newRight;
        } else {
            adder(node->left, val, depth, currentDepth + 1);
            adder(node->right, val, depth, currentDepth + 1);
        }
    }
};