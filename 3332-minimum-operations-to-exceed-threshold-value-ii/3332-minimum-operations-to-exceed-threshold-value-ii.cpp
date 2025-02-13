class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int num : nums) {
            pq.push(num);
        }
        int ops=0;
        // While we have at least 2 elements and smallest is < k
        while(pq.size() >= 2 && pq.top() < k) {
            // Get two smallest elements
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            // Calculate new element
            long long newElement = min(x, y) * 2 + max(x, y);
            // Add back to heap
            pq.push(newElement); 
            ops++;
        }
        // Check if we succeeded
        return pq.top() >= k ? ops: -1;
    }
};