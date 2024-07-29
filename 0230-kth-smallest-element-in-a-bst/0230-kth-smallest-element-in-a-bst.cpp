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
    int kthSmallest(TreeNode* root, int k) {
        ino(root,k);
        return res;
    }
private:
    int cnt{0},res{0};
    void ino(TreeNode *node,int k){
        if(node==NULL) return;
        ino(node->left,k);
        cnt++;
        if(cnt==k){
            res=node->val;
            return;
        }
        ino(node->right,k);
    }
};
//general approach-doing dfs traversal then storing all coming val in a vec then sort it and return required ele
//optimised--do inorder of bst--ascending order auto then return req ele along with counter//morris traversal