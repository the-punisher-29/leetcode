class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        int n = arr.size();
        long long result = 0;
        stack<int> s;  
        // Left boundary: previous smaller element
        vector<int> left(n, -1);
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        // Right boundary: next smaller element
        vector<int> right(n, n);
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        // Calculating the contribution of each element to the result
        for (int i = 0; i < n; ++i) {
            // Number of subarrays where arr[i] is the minimum
            // left[i] and right[i] mark the boundaries where arr[i] is the minimum
            long long count = (i - left[i]) * (right[i] - i);
            result = (result + count * arr[i]) % MOD;
        }
        return result;
    }
};