/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base
        if(root==NULL) return NULL;

        //p nd q > root then right st
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right,p,q);
        }

        // p nd q < root then left st
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        
        // if one small and one large than root then root obv
        return root;
    }
};