class Solution {
private:
    bool helpher(int x, int y, int x1, int y1, int x2, int y2) {
        return x >= x1 && x <= x2 && y >= y2 && y <= y1;
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int n = points.size();
        int vp = 0;
        // for (int alice = 0; alice < n; alice++) {
        //     for (int bob = 0; bob < n; bob++) {
        //         if (alice == bob) continue;
                
        //         int ax = points[alice][0], ay = points[alice][1];
        //         int bx = points[bob][0], by = points[bob][1];
                
        //         // Alice must be upper-left of Bob
        //         if (ax <= bx && ay >= by) {
        //             bool canBuildFence = true;
                    
        //             // Check if any other person interferes
        //             for (int other = 0; other < n; other++) {
        //                 if (other == alice || other == bob) continue;
                        
        //                 int ox = points[other][0], oy = points[other][1];
                        
        //                 if (helpher(ox, oy, ax, ay, bx, by)) {
        //                     canBuildFence = false;
        //                     break;
        //                 }
        //             }
                    
        //             if (canBuildFence) {
        //                 count++;
        //             }
        //         }
        //     }
        // }
        for (int i = 0; i < n; ++i) {
            int topLeftY = points[i][1];
            int highestBottomRightY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                int bottomRightY = points[j][1];
                // Valid pair if:
                // 1. Bottom-right Y is less than or equal to top-left Y
                // 2. Bottom-right Y is higher than any previous valid bottom-right Y
                //    (ensures no points exist inside the rectangle)
                if (highestBottomRightY < bottomRightY && bottomRightY <= topLeftY) {
                    highestBottomRightY = bottomRightY;
                    ++vp;
                }
            }
        }
        
        return vp;
    }
};