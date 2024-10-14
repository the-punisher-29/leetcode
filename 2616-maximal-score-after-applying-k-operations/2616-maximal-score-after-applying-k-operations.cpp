class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Create a max heap
        priority_queue<int> pq(nums.begin(), nums.end());
        
        long long score = 0;
        
        // Perform k operations
        for (int i = 0; i < k; ++i) {
            // Get the maximum element
            int max_elem = pq.top();
            pq.pop();
            
            // Increase the score
            score += max_elem;
            
            // Calculate the new value and push it back to the heap
            int new_val = (max_elem + 2) / 3;  // Equivalent to ceil(max_elem / 3)
            pq.push(new_val);
        }
        
        return score;
    }
};