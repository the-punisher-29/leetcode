class Solution {
public:
int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size(), ans = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 1; j < n; ++j)
            matrix[i][j] += matrix[i][j - 1];
    unordered_map<int, int> counter;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            counter.clear();
            counter[0] = 1;
            int sum = 0;
            for (int k = 0; k < m; ++k) {
                sum += matrix[k][j];
                if (i > 0) {
                    sum -= matrix[k][i - 1];
                }
                ans += counter[sum - target];
                counter[sum]++;
            }
        }
    }
    return ans;
}
};