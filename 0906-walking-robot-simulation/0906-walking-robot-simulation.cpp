class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Define direction vectors for north, east, south, west
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, dir = 0, maxDistSquared = 0;

        // Create a hash set for obstacles for O(1) lookups
        unordered_set<long long> obstacleSet;
        for (auto& obstacle : obstacles) {
            long long hash = obstacle[0] * 60001LL + obstacle[1];
            obstacleSet.insert(hash);
        }

        // Process each command
        for (int command : commands) {
            if (command == -2) { // Turn left
                dir = (dir + 3) % 4;
            } else if (command == -1) { // Turn right
                dir = (dir + 1) % 4;
            } else {
                // Move forward `command` steps
                for (int i = 0; i < command; ++i) {
                    int newX = x + directions[dir][0];
                    int newY = y + directions[dir][1];
                    long long hash = newX * 60001LL + newY;

                    // Check if the new position is an obstacle
                    if (obstacleSet.count(hash)) {
                        break; // Stop at the obstacle
                    }

                    // Update position
                    x = newX;
                    y = newY;
                    
                    // Update maximum distance squared
                    maxDistSquared = max(maxDistSquared, x * x + y * y);
                }
            }
        }

        return maxDistSquared;
    }
};