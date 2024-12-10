class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If the input is empty, return empty vector
        if (intervals.empty()) return {};
        
        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });
        
        // Result vector to store merged intervals
        vector<vector<int>> merged;
        
        // Add the first interval to the result
        merged.push_back(intervals[0]);
        
        // Iterate through the remaining intervals
        for (int i = 1; i < intervals.size(); i++) {
            // If current interval overlaps with the last interval in merged
            if (intervals[i][0] <= merged.back()[1]) {
                // Merge by updating the end time of the last interval
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
            else {
                // No overlap, add the current interval to merged
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;
    }
};