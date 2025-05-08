class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        // Distance matrix to store minimum time to reach each room with a specific move count parity
        // dist[i][j][k] where k=0 means even number of moves made so far, k=1 means odd
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        // Priority queue for Dijkstra's algorithm (time, row, col, moveParity)
        // moveParity: 0 for even number of moves (next move takes 1 second)
        //             1 for odd number of moves (next move takes 2 seconds)
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
        
        // Start from room (0, 0) at time 0 with 0 moves made (even parity)
        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});
        
        while (!pq.empty()) {
            auto [time, row, col, moveParity] = pq.top();
            pq.pop();
            
            // If this is not the most up-to-date time, skip
            if (time > dist[row][col][moveParity]) continue;
            
            // If we reached the target room, return the time
            if (row == n - 1 && col == m - 1) return time;
            
            // Try to move to all adjacent rooms
            for (auto [dr, dc] : dirs) {
                int newRow = row + dr;
                int newCol = col + dc;
                
                // Check if the new room is valid
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    // We can start moving to the adjacent room at max(time, moveTime[newRow][newCol])
                    int startMoveTime = max(time, moveTime[newRow][newCol]);
                    
                    // Calculate move time based on parity (alternating 1 and 2 seconds)
                    int moveTime = (moveParity == 0) ? 1 : 2;
                    
                    // Time to arrive at the new room
                    int arrivalTime = startMoveTime + moveTime;
                    
                    // New move parity after this move
                    int newMoveParity = 1 - moveParity;
                    
                    // If we found a better time to reach this room with this move parity, update it
                    if (arrivalTime < dist[newRow][newCol][newMoveParity]) {
                        dist[newRow][newCol][newMoveParity] = arrivalTime;
                        pq.push({arrivalTime, newRow, newCol, newMoveParity});
                    }
                }
            }
        }
        
        // If we can't reach the target room (shouldn't happen based on constraints)
        return -1;
    }
};