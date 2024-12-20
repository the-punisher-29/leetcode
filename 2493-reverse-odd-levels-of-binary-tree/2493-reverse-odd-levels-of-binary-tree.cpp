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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> levelNodes;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                levelNodes.push_back(curr);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            if (level % 2 == 1) {
                int left = 0, right = size - 1;
                while (left < right) {
                    int temp = levelNodes[left]->val;
                    levelNodes[left]->val = levelNodes[right]->val;
                    levelNodes[right]->val = temp;
                    left++;
                    right--;
                }
            }
            level++;
        }
        return root;
    }
};