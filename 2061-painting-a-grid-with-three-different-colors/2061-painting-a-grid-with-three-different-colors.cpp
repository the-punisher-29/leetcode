class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;
        // If m > n, swapping them for efficiency (since i'll encode rows)
        if (m > n) {
            return colorTheGrid(n, m);
        }
        vector<int> validStates;
        generateValidStates(0, 0, m, 0, validStates);
        int stateCount = validStates.size();
        vector<vector<bool>> compatible(stateCount, vector<bool>(stateCount, false));
        for (int i = 0; i < stateCount; i++) {
            for (int j = 0; j < stateCount; j++) {
                compatible[i][j] = areCompatible(validStates[i], validStates[j], m);
            }
        }
        // dp[i][j] = number of ways to color i rows with the i-th row having state j
        vector<vector<long long>> dp(n + 1, vector<long long>(stateCount, 0));
        // Base case: first row can be colored in any valid state
        for (int j = 0; j < stateCount; j++) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < stateCount; j++) {
                for (int k = 0; k < stateCount; k++) {
                    if (compatible[k][j]) {
                        dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                    }
                }
            }
        }
        // Summing up all valid ways to color n rows
        long long result = 0;
        for (int j = 0; j < stateCount; j++) {
            result = (result + dp[n][j]) % MOD;
        }
        return result;
    }
    
private:
    // m: row length
    // prev: previous color (0: none, 1: red, 2: green, 3: blue)
    void generateValidStates(int state, int pos, int m, int prev, vector<int>& validStates) {
        if (pos == m) {
            validStates.push_back(state);
            return;
        }
        // Trying each color (1: red, 2: green, 3: blue)
        for (int color = 1; color <= 3; color++) {
            if (color != prev) { // No adjacent cells with the same color
                generateValidStates(state * 3 + (color - 1), pos + 1, m, color, validStates);
            }
        }
    }
    // Checking if two row states are compatible (no vertical adjacent cells with the same color)
    bool areCompatible(int state1, int state2, int m) {
        for (int i = 0; i < m; i++) {
            int color1 = state1 % 3;
            int color2 = state2 % 3;
            if (color1 == color2) {
                return false;
            }
            state1 /= 3;
            state2 /= 3;
        }
        return true;
    }
};