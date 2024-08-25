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
 //recur sol---trivial
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> res;
//         posto(root,res);
//         return res;
//     }
// private:
//     void posto(TreeNode* node,vector<int> &res){
//         if(node==NULL){
//             return;
//         }
//         posto(node->left,res);
//         posto(node->right,res);
//         res.push_back(node->val);
//     }
// };

//iter sol---interes
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> st;
        TreeNode *curr = root;
        TreeNode *lastVisited = NULL;
        while (!st.empty() || curr != NULL) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode *node = st.top();
                if (node->right != NULL && lastVisited != node->right) {
                    curr = node->right;
                } else {
                    res.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }
        return res;
    }
};