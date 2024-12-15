class Solution {
public:
    // Custom comparator to define priority in the max heap
    struct ClassCompare {
        // Calculate the potential increase in pass ratio if we add a student to this class
        double getPotentialIncrease(int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        }
        
        // Overload the () operator for priority queue comparison
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return getPotentialIncrease(a[0], a[1]) < getPotentialIncrease(b[0], b[1]);
        }
    };
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Create a max heap using custom comparator
        // We want classes with highest potential increase in pass ratio to be at the top
        priority_queue<vector<int>, vector<vector<int>>, ClassCompare> pq(classes.begin(), classes.end());
        
        // Distribute extra students to classes that benefit most
        while (extraStudents--) {
            // Get the class that would benefit most from an extra student
            auto curr = pq.top();
            pq.pop();
            
            // Add a student to this class
            curr[0]++;
            curr[1]++;
            
            // Put the modified class back into the priority queue
            pq.push(curr);
        }
        
        // Calculate the average pass ratio after distribution
        double totalPassRatio = 0.0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            // Add pass ratio of each class
            totalPassRatio += (double)curr[0] / curr[1];
        }
        
        // Return average pass ratio
        return totalPassRatio / classes.size();
    }
};