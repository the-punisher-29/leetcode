class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        for (auto& dir : directions) {
            dfs(grid, i + dir[0], j + dir[1]);
        }
    }
    
    int countIslands(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    bool isDisconnected(vector<vector<int>>& grid) {
        vector<vector<int>> gridCopy = grid;
        int islands = countIslands(gridCopy);
        return islands != 1;
    }
    
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // Check if already disconnected
        if (isDisconnected(grid)) return 0;
        
        // Check if can be disconnected in one day
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (isDisconnected(grid)) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        // If not, it can always be disconnected in 2 days
        return 2;
    }
};