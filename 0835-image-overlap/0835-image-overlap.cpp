class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> pts1, pts2;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) pts1.push_back({i, j});
                if (img2[i][j] == 1) pts2.push_back({i, j});
            }
        if (pts1.empty() || pts2.empty()) return 0;
        unordered_map<int, int> freq; // encode (dx,dy) as a single int key
        int best = 0;
        for (auto& p1 : pts1) {
            for (auto& p2 : pts2) {
                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;
                // n <= 30, so dx,dy in [-29,29]; encode with an offset to keep it positive
                int key = (dx + 60) * 200 + (dy + 60);
                int cnt = ++freq[key];
                best = max(best, cnt);
            }
        }
        return best;
    }
};