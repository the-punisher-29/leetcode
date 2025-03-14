class Solution {
public:
    // Efficient O(n) solution using monotonic stack
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        // Calculating contribution of each element as maximum
        stack<int> s;
        vector<int> left_max(n), right_max(n);
        // Finding left boundary where nums[i] is maximum
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }
            left_max[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        // Finding right boundary where nums[i] is maximum
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }
            right_max[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        // Calculating contribution of each element as minimum
        while (!s.empty()) s.pop();
        vector<int> left_min(n), right_min(n);
        // Finding left boundary where nums[i] is minimum
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            left_min[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        // Finding right boundary where nums[i] is minimum
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }
            right_min[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        for (int i = 0; i < n; ++i) {
            long long count_as_max = (long long)(i - left_max[i]) * (right_max[i] - i);
            long long count_as_min = (long long)(i - left_min[i]) * (right_min[i] - i);
            sum += nums[i] * (count_as_max - count_as_min);
        }
        
        return sum;
    }
};