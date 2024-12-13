class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        // Create a min-heap with (value, index) pairs
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        // Populate the priority queue
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        // Track marked elements
        vector<bool> marked(n, false);
        // Total score
        long long score = 0;
        // Process until queue is empty
        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            // Skip if already marked
            if (marked[idx]) continue;
            // Add to score
            score += val;
            // Mark current element
            marked[idx] = true;
            // Mark left adjacent if exists
            if (idx > 0) marked[idx-1] = true;
            // Mark right adjacent if exists
            if (idx < n-1) marked[idx+1] = true;
        }
        return score;
    }
};