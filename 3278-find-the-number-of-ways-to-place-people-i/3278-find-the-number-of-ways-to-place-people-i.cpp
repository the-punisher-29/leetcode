class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int x1 = points[i][0], y1 = points[i][1];  // Point A
                int x2 = points[j][0], y2 = points[j][1];  // Point B
                // Check if A is upper left of B
                if (x1 <= x2 && y1 >= y2) {
                    bool validPair = true;
                    // Check if any other point lies in the rectangle
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        int x = points[k][0], y = points[k][1];
                        // Check if point k is within rectangle (including borders)
                        if (x >= x1 && x <= x2 && y <= y1 && y >= y2) {
                            validPair = false;
                            break;
                        }
                    }
                    if (validPair) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};