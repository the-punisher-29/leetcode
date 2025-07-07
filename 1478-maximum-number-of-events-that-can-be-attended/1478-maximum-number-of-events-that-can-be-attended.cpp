class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        set<int> availableDays;
        // Find the range of days we need to consider
        int minDay = INT_MAX, maxDay = INT_MIN;
        for (const auto& event : events) {
            minDay = min(minDay, event[0]);
            maxDay = max(maxDay, event[1]);
        }
        // Initialize all days as available
        for (int day = minDay; day <= maxDay; day++) {
            availableDays.insert(day);
        }
        int count = 0;
        // Process each event in order of end day
        for (const auto& event : events) {
            int start = event[0];
            int end = event[1];
            // Find the earliest available day within the event's range
            auto it = availableDays.lower_bound(start);
            // If we found a day within the event's range
            if (it != availableDays.end() && *it <= end) {
                count++;
                availableDays.erase(it);  // Mark this day as occupied
            }
        }
        return count;
    }
};