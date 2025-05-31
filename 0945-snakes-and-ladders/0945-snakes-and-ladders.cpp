class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;
        // Helper function to convert square number to (row, col) coordinates
        auto getCoordinates = [&](int square) -> pair<int, int> {
            square--; // Convert to 0-indexed
            int row = n - 1 - square / n;
            int col = square % n;
            // Handle boustrophedon (alternating direction)
            if ((n - 1 - row) % 2 == 1) {
                col = n - 1 - col;
            }
            return {row, col};
        };
        
        // BFS to find minimum moves
        queue<int> q;
        vector<bool> visited(target + 1, false);
        q.push(1);
        visited[1] = true;
        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            // Process all squares at current distance
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                //if we reached the target
                if (curr == target) {
                    return moves;
                }
                //all possible dice rolls (1-6)
                for (int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;
                    if (next > target) break;
                    auto [row, col] = getCoordinates(next);
                    // Check for snake or ladder
                    if (board[row][col] != -1) {
                        next = board[row][col];
                    }
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            
            moves++;
        }
        
        return -1; // Target not reachable
    }
};