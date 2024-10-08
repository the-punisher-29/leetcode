class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicSquare(grid, i, j)) count++;
            }
        }
        
        return count;
    }

        bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        vector<int> count(10, 0);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || count[num] > 0) return false;
                count[num]++;
            }
        }
        
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        
        // Check rows
        for (int i = r; i < r + 3; i++) {
            if (grid[i][c] + grid[i][c+1] + grid[i][c+2] != sum) return false;
        }
        
        // Check columns
        for (int j = c; j < c + 3; j++) {
            if (grid[r][j] + grid[r+1][j] + grid[r+2][j] != sum) return false;
        }
        
        // Check diagonals
        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum) return false;
        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum) return false;
        
        return true;
    }


};