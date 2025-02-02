class Solution {
private:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check column conflicts
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // Check diagonal conflicts (upper left)
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // Check diagonal conflicts (upper right)
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(int row, vector<string>& board, vector<vector<string>>& result, int n) {
        // Base case: if we've placed queens in all rows
        if (row == n) {
            result.push_back(board);
            return;
        }
        // Try placing a queen in each column of current row
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, result, n);
                board[row][col] = '.';  // backtrack
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(0, board, result, n);
        return result;
    }
};