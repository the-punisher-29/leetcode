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
private:
    bool findPath(TreeNode* node, int value, string& path) {
        if (!node) return false;

        if (node->val == value) return true;
        
        if (findPath(node->left, value, path)) {
            path.push_back('L');
            return true;
        }
        
        if (findPath(node->right, value, path)) {
            path.push_back('R');
            return true;
        }
        
        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);
        
        // Reverse the paths as they are from node to root
        reverse(startPath.begin(), startPath.end());
        reverse(destPath.begin(), destPath.end());
        
        // Find the LCA
        int i = 0;
        while (i < startPath.length() && i < destPath.length() && startPath[i] == destPath[i]) {
            i++;
        }
        
        // Construct the final path
        string result(startPath.length() - i, 'U');
        result += destPath.substr(i);
        
        return result;
    }
};