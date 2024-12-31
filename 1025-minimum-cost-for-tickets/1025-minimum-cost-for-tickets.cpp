class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travelDays(days.begin(), days.end());
        vector<int> dp(366);
        for (int day = 1; day <= 365; day++) {
            if (travelDays.find(day) == travelDays.end()) {
                dp[day] = dp[day - 1];
                continue;
            }
            int option1 = dp[day - 1] + costs[0];
            int option2 = dp[max(0, day - 7)] + costs[1];
            int option3 = dp[max(0, day - 30)] + costs[2];
            dp[day] = min({option1, option2, option3});
        }
        return dp[days.back()];
    }
};