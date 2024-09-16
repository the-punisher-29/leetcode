class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) return 0;

        vector<int> minutes;
        for (const string& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            minutes.push_back(hour * 60 + minute);
        }
        sort(minutes.begin(), minutes.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }
        // Handle wrap-around case
        int wrapAround = 1440 - minutes.back() + minutes.front();
        minDiff = min(minDiff, wrapAround);
        
        return minDiff;
    }
};