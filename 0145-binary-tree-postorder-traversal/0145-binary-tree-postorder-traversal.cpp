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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        posto(root,res);
        return res;
    }
private:
    void posto(TreeNode* node,vector<int> &res){
        if(node==NULL){
            return;
        }
        posto(node->left,res);
        posto(node->right,res);
        res.push_back(node->val);
    }
};