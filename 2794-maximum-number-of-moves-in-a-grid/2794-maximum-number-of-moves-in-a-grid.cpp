class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();    // number of rows
        int n = grid[0].size(); // number of columns
        int maxMovesPossible = 0;
        
        // dp[i][j] represents the maximum moves possible starting from cell (i,j)
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // Try starting from each cell in first column
        for(int i = 0; i < m; i++) {
            maxMovesPossible = max(maxMovesPossible, dfs(i, 0, grid, dp));
        }
        
        return maxMovesPossible;
    }
    
private:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // If already calculated, return memoized result
        if(dp[row][col] != -1) return dp[row][col];
        
        int m = grid.size();
        int n = grid[0].size();
        int maxMoves = 0;
        
        // For each cell, we can move to three possible cells in next column
        // if they are within bounds and have strictly greater value
        for(int nextRow = row-1; nextRow <= row+1; nextRow++) {
            int nextCol = col + 1;
            
            // Check bounds and value condition
            if(nextRow >= 0 && nextRow < m && nextCol < n && 
               grid[nextRow][nextCol] > grid[row][col]) {
                maxMoves = max(maxMoves, 1 + dfs(nextRow, nextCol, grid, dp));
            }
        }
        
        // Store result in dp array
        dp[row][col] = maxMoves;
        return maxMoves;
    }
};