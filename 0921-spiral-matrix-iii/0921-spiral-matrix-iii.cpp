class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result = {{rStart, cStart}};
        int steps = 0;
        int direction = 0;
        int total = rows * cols;
        
        // Directions: East, South, West, North
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (result.size() < total) {
            if (direction == 0 || direction == 2) {
                steps++; // Increase steps when moving East or West
            }
            
            for (int i = 0; i < steps; i++) {
                rStart += dirs[direction][0];
                cStart += dirs[direction][1];
                
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    result.push_back({rStart, cStart});
                }
                
                if (result.size() == total) {
                    return result;
                }
            }
            
            direction = (direction + 1) % 4; // Change direction
        }
        
        return result;
    }
};