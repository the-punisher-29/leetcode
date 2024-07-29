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
 #define ll long long
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,LLONG_MIN,LLONG_MAX);
    }
private:
   bool helper(TreeNode* node,ll minv,ll maxv){
    if(node==NULL) return true;
    if(node->val<=minv || node->val>=maxv){
        return false;
    }
    return helper(node->left,minv,node->val) && helper(node->right,node->val,maxv);
   }
};