class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] > 0) {
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }
        
        return maxGold;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return 0;
        }
        
        int gold = grid[x][y];
        grid[x][y] = 0; // Mark the cell as visited
        
        int maxGold = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            maxGold = max(maxGold, dfs(grid, newX, newY));
        }
        
        grid[x][y] = gold; // Backtrack and restore the cell's value
        return gold + maxGold;
    }
};
