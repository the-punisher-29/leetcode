class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    
private:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int m = grid1.size();
        int n = grid1[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) {
            return true;
        }
        if (grid1[i][j] == 0) {
            return false;
        }
        grid2[i][j] = 0;  // Mark as visited
        bool isSubIsland = true;
        isSubIsland &= dfs(grid1, grid2, i-1, j);
        isSubIsland &= dfs(grid1, grid2, i+1, j);
        isSubIsland &= dfs(grid1, grid2, i, j-1);
        isSubIsland &= dfs(grid1, grid2, i, j+1);
        return isSubIsland;
    }
};