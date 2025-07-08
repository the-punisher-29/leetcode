class Solution {
public:
    int maxValue(vector<vector<int>>& events, int maxEvents) {
        // Sort the events based on their end time
        sort(events.begin(), events.end(), [](const auto& event1, const auto& event2) {
            return event1[1] < event2[1];
        });

        int numEvents = events.size();
        int dp[numEvents + 1][maxEvents + 1];

        // Initialize the dp array with zero
        memset(dp, 0, sizeof(dp));

        // Loop through all events
        for (int i = 1; i <= numEvents; ++i) {
            // Get the start time and value of the current event
            int startTime = events[i - 1][0];
            int value = events[i - 1][2];

            // Create a vector that holds the start time
            vector<int> currentTime = {startTime};

            // Find the last event that finishes before the current event starts
            int lastEventIndex = lower_bound(events.begin(), events.begin() + i - 1, currentTime, [](const auto& a, const auto& b) {
                return a[1] < b[0];
            }) - events.begin();

            // Loop through the numbers 1 to maxEvents
            for (int j = 1; j <= maxEvents; ++j) {
                // Update the dp array with the max value achieved by either
                // skipping the current event or attending it after the last non-overlapping event
                dp[i][j] = max(dp[i - 1][j], dp[lastEventIndex][j - 1] + value);
            }
        }

        // Return the maximum value that can be achieved by attending maxEvents number of events
        return dp[numEvents][maxEvents];
    }
};
