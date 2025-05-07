class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        // Define directions for adjacent rooms (up, right, down, left)
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // Distance matrix to store minimum time to reach each room
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        // Priority queue for Dijkstra's algorithm (time, row, col)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        // Start from room (0, 0) at time 0
        dist[0][0] = 0;
        pq.push({0, 0, 0});
        
        while (!pq.empty()) {
            auto [time, row, col] = pq.top();
            pq.pop();
            
            // If this is not the most up-to-date time, skip
            if (time > dist[row][col]) continue;
            
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
                    
                    // It takes 1 second to move between rooms
                    int arrivalTime = startMoveTime + 1;
                    
                    // If we found a better time to reach this room, update it
                    if (arrivalTime < dist[newRow][newCol]) {
                        dist[newRow][newCol] = arrivalTime;
                        pq.push({arrivalTime, newRow, newCol});
                    }
                }
            }
        }
        
        // If we can't reach the target room (shouldn't happen based on constraints)
        return -1;
    }
};