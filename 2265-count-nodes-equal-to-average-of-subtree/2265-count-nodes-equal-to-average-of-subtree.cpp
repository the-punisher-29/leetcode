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
    int result = 0;
    // this i defined to return {sum, count} of the subtree rooted at node
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);
        int sum = leftSum + rightSum + node->val;
        int count = leftCount + rightCount + 1;
        if (node->val == sum / count) {
            result++;
        }
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return result;
    }
};