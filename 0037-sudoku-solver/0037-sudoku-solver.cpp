class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // Check row
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == num) return false;
        }
        // Check column
        for (int x = 0; x < 9; x++) {
            if (board[x][col] == num) return false;
        }
        // Check 3x3 box
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        int row = -1, col = -1;
        bool isEmpty = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    row = i;
                    col = j;
                    isEmpty = true;
                    break;
                }
            }
            if (isEmpty) break;
        }
        // If no empty cell found, puzzle is solved
        if (!isEmpty) return true;
        for (char num = '1'; num <= '9'; num++) {
            if (isValid(board, row, col, num)) {
                board[row][col] = num;
                if (solve(board)) return true;
                board[row][col] = '.';  // backtrack
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};