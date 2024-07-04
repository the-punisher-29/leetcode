class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Multi-source BFS to compute minimum distance to any thief
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && distance[nx][ny] > distance[x][y] + 1) {
                    distance[nx][ny] = distance[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        int left = 0, right = n * 2, result = 0;
        
        auto isValid = [&](int minSafeness) {
            if (distance[0][0] < minSafeness) return false;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                if (x == n - 1 && y == n - 1) return true;

                for (auto& dir : directions) {
                    int nx = x + dir.first, ny = y + dir.second;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && distance[nx][ny] >= minSafeness) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            return false;
        };

        // Binary search on the safeness factor
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};