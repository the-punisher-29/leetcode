class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int a, int b) {
            if (intervals[a][1] != intervals[b][1]) return intervals[a][1] < intervals[b][1];
            return intervals[a][0] < intervals[b][0];
        });
        vector<long long> l(n), r(n), w(n);
        vector<int> origIdx(n);
        for (int i = 0; i < n; i++) {
            l[i] = intervals[ord[i]][0];
            r[i] = intervals[ord[i]][1];
            w[i] = intervals[ord[i]][2];
            origIdx[i] = ord[i];
        }
        // pred[p] = number of intervals among sorted positions [0..p-1] with r < l[p]
        vector<int> pred(n);
        for (int p = 0; p < n; p++) {
            int lo = 0, hi = p - 1, res = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (r[mid] < l[p]) { res = mid; lo = mid + 1; }
                else hi = mid - 1;
            }
            pred[p] = res + 1;
        }
        struct State {
            long long score;
            vector<int> indices; // sorted ascending
        };
        vector<vector<State>> dp(n + 1, vector<State>(5, State{0, {}}));
        for (int i = 1; i <= n; i++) {
            int cur = i - 1;
            for (int k = 0; k <= 4; k++) {
                if (k == 0) { dp[i][k] = dp[i - 1][k]; continue; }
                State skipOpt = dp[i - 1][k];
                State takeOpt = dp[pred[cur]][k - 1];
                takeOpt.score += w[cur];
                auto pos = upper_bound(takeOpt.indices.begin(), takeOpt.indices.end(), origIdx[cur]);
                takeOpt.indices.insert(pos, origIdx[cur]);
                bool takeIsBetter = (takeOpt.score > skipOpt.score) ||
                                     (takeOpt.score == skipOpt.score && takeOpt.indices < skipOpt.indices);

                dp[i][k] = takeIsBetter ? takeOpt : skipOpt;
            }
        }
        return dp[n][4].indices;
    }
};