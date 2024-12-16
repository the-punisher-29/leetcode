class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        while (k--) {
            int minVal = pq.top().first;
            int minIdx = pq.top().second;
            pq.pop();
            minVal *= multiplier;
            pq.push({minVal, minIdx});
        }
        vector<int> result(nums.size());
        while (!pq.empty()) {
            result[pq.top().second] = pq.top().first;
            pq.pop();
        }
        return result;
    }
};