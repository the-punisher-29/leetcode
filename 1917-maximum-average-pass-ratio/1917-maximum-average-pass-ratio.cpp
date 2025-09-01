class Solution {
public:
    struct ClassCompare {
        double getPotentialIncrease(int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        }
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return getPotentialIncrease(a[0], a[1]) < getPotentialIncrease(b[0], b[1]);
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<int>, vector<vector<int>>, ClassCompare> pq(classes.begin(), classes.end());
        while (extraStudents--) {
            auto curr = pq.top();
            pq.pop();
            curr[0]++;
            curr[1]++;
            pq.push(curr);
        }
        double totalPassRatio = 0.0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            totalPassRatio += (double)curr[0] / curr[1];
        }
        return totalPassRatio / classes.size();
    }
};