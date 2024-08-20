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
 //recur
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>res;
//         po(root,res);
//         return res;
//     }
// private:
//    void po(TreeNode *node,vector<int> &res){
//     if(node==NULL){
//         return;
//     }
//     res.push_back(node->val);
//     po(node->left,res);
//     po(node->right,res);
//    }
// };
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            result.push_back(curr->val);
            
            if (curr->right) {
                st.push(curr->right);
            }
            if (curr->left) {
                st.push(curr->left);
            }
        }
        
        return result;
    }
};