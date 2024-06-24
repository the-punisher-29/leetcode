class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Sort balloons based on their end positions
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int end_pos = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end_pos) {
                // Balloon cannot be burst with the current arrow, shoot another arrow
                ++arrows;
                end_pos = points[i][1];
            }
        }

        return arrows;
    }
};