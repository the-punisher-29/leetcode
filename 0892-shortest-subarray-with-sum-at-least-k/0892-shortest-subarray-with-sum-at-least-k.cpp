class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        // Use long to handle potential overflow
        vector<long> prefixSum(n + 1, 0);
        
        // Calculate prefix sums
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        // We use deque to maintain a monotonic queue
        deque<int> monoQueue;
        int minLen = INT_MAX;
        
        for(int i = 0; i <= n; i++) {
            // For each new prefix sum, we check if we can find a valid subarray
            // by comparing with prefix sums in the monotonic queue
            while(!monoQueue.empty() && prefixSum[i] - prefixSum[monoQueue.front()] >= k) {
                minLen = min(minLen, i - monoQueue.front());
                monoQueue.pop_front();
            }
            
            // Maintain monotonic increasing property
            // Remove larger prefix sums from the back as they won't give us
            // a shorter valid subarray in the future
            while(!monoQueue.empty() && prefixSum[i] <= prefixSum[monoQueue.back()]) {
                monoQueue.pop_back();
            }
            
            monoQueue.push_back(i);
        }
        
        return minLen == INT_MAX ? -1 : minLen;
    }
};