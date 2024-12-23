class Solution {
private:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {arr[i], i};
        }
        sort(pairs.begin(), pairs.end());
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || pairs[i].second == i)
                continue;
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = pairs[j].second;
                cycleSize++;
            }
            if (cycleSize > 0) {
                swaps += (cycleSize - 1);
            }
        }
        return swaps;
    }
    
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        int totalSwaps = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            totalSwaps += minSwaps(levelValues);
        }
        return totalSwaps;
    }
};