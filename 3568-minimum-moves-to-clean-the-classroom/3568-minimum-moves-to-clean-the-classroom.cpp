class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1;
        vector<pair<int,int>> litter;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                char ch = classroom[i][j];
                if (ch == 'S') { sr = i; sc = j; }
                else if (ch == 'L') litter.push_back({i, j});
            }

        int k = litter.size();
        if (k == 0) return 0;

        // map each litter cell -> bit index
        unordered_map<int,int> litterBit;
        for (int i = 0; i < k; i++)
            litterBit[litter[i].first * n + litter[i].second] = i;

        int fullMask = (1 << k) - 1;
        int E = energy + 1;   // energy levels 0..energy
        int M = 1 << k;       // number of masks

        auto encode = [&](int r, int c, int mask, int e) {
            return ((r * n + c) * M + mask) * E + e;
        };

        long long total = 1LL * m * n * M * E;
        vector<bool> visited(total, false);

        int startState = encode(sr, sc, 0, energy);
        visited[startState] = true;

        static const int dr[4] = {-1, 1, 0, 0};
        static const int dc[4] = {0, 0, -1, 1};

        queue<int> q;
        q.push(startState);
        int depth = 0;

        while (!q.empty()) {
            int sz = q.size();
            depth++;
            for (int i = 0; i < sz; i++) {
                int state = q.front(); q.pop();

                int e = state % E;
                int tmp = state / E;
                int mask = tmp % M;
                int pos = tmp / M;
                int r = pos / n, c = pos % n;

                if (e == 0) continue; // stuck: no energy, not on R

                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + dr[dir], nc = c + dc[dir];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    char cell = classroom[nr][nc];
                    if (cell == 'X') continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if (cell == 'L') {
                        auto it = litterBit.find(nr * n + nc);
                        if (it != litterBit.end()) nmask |= (1 << it->second);
                    }
                    if (cell == 'R') ne = energy; // reset overrides the -1, not adds to it

                    if (nmask == fullMask) return depth;

                    int nstate = encode(nr, nc, nmask, ne);
                    if (!visited[nstate]) {
                        visited[nstate] = true;
                        q.push(nstate);
                    }
                }
            }
        }

        return -1;
    }
};