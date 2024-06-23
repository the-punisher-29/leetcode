class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque;    // Deque to store indices of potential maximum values
        deque<int> minDeque;    // Deque to store indices of potential minimum values
        int left = 0;           // Left pointer of the window
        int result = 0;         // Length of the longest valid subarray

        for (int right = 0; right < nums.size(); right++) {
            // Maintain maxDeque (remove smaller elements from the back)
            while (!maxDeque.empty() && nums[maxDeque.back()] < nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            // Maintain minDeque (remove larger elements from the back)
            while (!minDeque.empty() && nums[minDeque.back()] > nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            // Shrink the window if the difference exceeds the limit
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                left++;  // Move the left pointer

                // Remove indices outside the current window
                if (maxDeque.front() < left) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() < left) {
                    minDeque.pop_front();
                }
            }

            // Update the result with the longest valid subarray found so far
            result = max(result, right - left + 1);
        }

        return result;
    }
};