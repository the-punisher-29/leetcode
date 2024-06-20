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
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
    int dfs(TreeNode* node,int cS){
        if(!node){
            return 0;
        }
        int nS=cS*10+node->val;
        //if reaches leaf..gives sum as op
        if(!node->left && !node->right){
            return nS;
        }
        //recurssee
        return dfs(node->left,nS)+dfs(node->right,nS);
    }
};