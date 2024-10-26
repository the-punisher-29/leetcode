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
    unordered_map<TreeNode*, int> height;       // Height of subtree rooted at node
    unordered_map<TreeNode*, int> depth;        // Depth of node from root
    unordered_map<int, TreeNode*> valToNode;    // Value to node mapping
    unordered_map<int, vector<int>> depthHeight;// Max heights at each depth level

    // Calculate depth and height for each node in a single traversal
    int calcDepthAndHeight(TreeNode* node, int d) {
        if (!node) return -1;

        depth[node] = d;
        valToNode[node->val] = node;
        
        int leftHeight = node->left ? calcDepthAndHeight(node->left, d + 1) : -1;
        int rightHeight = node->right ? calcDepthAndHeight(node->right, d + 1) : -1;
        
        height[node] = 1 + max(leftHeight, rightHeight);
        
        if (depthHeight.find(d) == depthHeight.end()) {
            depthHeight[d] = {height[node]};
        } else {
            depthHeight[d].push_back(height[node]);
            if (depthHeight[d].size() > 2) {
                nth_element(depthHeight[d].begin(), depthHeight[d].begin() + 1, depthHeight[d].end(), greater<int>());
                depthHeight[d].resize(2);
            }
        }
        
        return height[node];
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height.clear();
        depth.clear();
        valToNode.clear();
        depthHeight.clear();
        
        // Calculate depths and heights in a single traversal
        calcDepthAndHeight(root, 0);
        
        vector<int> result;
        for (int q : queries) {
            TreeNode* nodeToRemove = valToNode[q];
            int d = depth[nodeToRemove];
            int heightWithoutNode = 0;

            if (depthHeight[d].size() == 1) {
                heightWithoutNode = d - 1;
            } else if (depthHeight[d][0] == height[nodeToRemove]) {
                heightWithoutNode = d + depthHeight[d][1];
            } else {
                heightWithoutNode = d + depthHeight[d][0];
            }
            
            result.push_back(heightWithoutNode);
        }
        
        return result;
    }
};
