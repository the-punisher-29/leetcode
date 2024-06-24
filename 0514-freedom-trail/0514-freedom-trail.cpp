class Solution {
public:
    int findRotateSteps(string ring, string key) {
        memo.clear();
        return dp(ring, key, 0, 0);
    }

private:
    unordered_map<string, int> memo;

    int dp(const string& ring, const string& key, int rIndex, int kIndex) {
        if (kIndex == key.size()) return 0;
        string state = to_string(rIndex) + "-" + to_string(kIndex);
        if (memo.count(state)) return memo[state];

        int clockwiseSteps = 0;
        int anticlockwiseSteps = 0;
        int ringSize = ring.size();
        int minSteps;

        for (int i = 0; i < ringSize; ++i) {
            if (ring[i] == key[kIndex]) {
                int diffClockwise = (i - rIndex + ringSize) % ringSize;
                int diffAnticlockwise = (rIndex - i + ringSize) % ringSize;

                int nextIndex = dp(ring, key, i, kIndex + 1);
                clockwiseSteps = diffClockwise + nextIndex;
                anticlockwiseSteps = diffAnticlockwise + nextIndex;

                minSteps = min(minSteps, min(clockwiseSteps, anticlockwiseSteps));
            }
        }

        memo[state] = minSteps + 1;
        return minSteps + 1;
    }
};