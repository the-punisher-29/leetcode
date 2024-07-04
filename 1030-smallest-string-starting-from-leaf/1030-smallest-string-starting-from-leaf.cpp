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
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }
    
    string dfs(TreeNode* node, string suffix) {
        if (!node) return suffix;
        
        suffix = string(1, 'a' + node->val) + suffix;
        
        if (!node->left && !node->right) return suffix;
        
        string leftStr = node->left ? dfs(node->left, suffix) : "";
        string rightStr = node->right ? dfs(node->right, suffix) : "";
        
        if (leftStr.empty()) return rightStr;
        if (rightStr.empty()) return leftStr;
        
        return min(leftStr, rightStr);
    }
};