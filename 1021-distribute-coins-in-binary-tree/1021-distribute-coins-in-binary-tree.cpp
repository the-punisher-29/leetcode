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
    int distributeCoins(TreeNode* root) {
        int moves=0;
        bC(root,moves);
        return moves;
    }
private:
   int bC(TreeNode* node,int& moves){
    if(!node) return 0;
    int left=bC(node->left,moves);
    int right=bC(node->right,moves);
    int balance=node->val+left+right-1;
    moves+=abs(balance);
    return balance;
   }
};