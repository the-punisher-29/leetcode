class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trusts_given(n + 1, 0);
    vector<int> trusts_received(n + 1, 0);
    // Iterating through the trust array to count trusts
    for (const auto& pair : trust) {
        int a = pair[0];
        int b = pair[1];
        trusts_given[a]++;
        trusts_received[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (trusts_received[i] == n - 1 && trusts_given[i] == 0) {
            return i;
        }
    }
    return -1;
    }
};