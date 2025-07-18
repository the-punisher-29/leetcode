using ll = long long;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 3;
        ll sum = 0;
        ll prefixSum[m + 1];
        priority_queue<int> maxHeap;
        for (int i = 1; i <= n * 2; ++i) {
            int element = nums[i - 1];
            sum += element;
            maxHeap.push(element);
            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            prefixSum[i] = sum;
        }
        sum = 0;
        ll suffixSum[m + 1];
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = m; i > n; --i) {
            int element = nums[i - 1];
            sum += element;
            minHeap.push(element);
            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            suffixSum[i] = sum;
        }
        ll ans = 1e18;
        for (int i = n; i <= n * 2; ++i) {
            ans = min(ans, prefixSum[i] - suffixSum[i + 1]);
        }
        return ans;
    }
};