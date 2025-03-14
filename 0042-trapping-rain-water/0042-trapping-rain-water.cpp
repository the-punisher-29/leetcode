class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        int left = 0, right = n - 1;
        int leftMax = height[left], rightMax = height[right];
        int result = 0;
        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                // If current height is less than leftMax, we can trap water here
                if (height[left] < leftMax) {
                    result += leftMax - height[left];
                } else {
                    // Updating leftMax if we find a taller bar
                    leftMax = height[left];
                }
            } else {
                right--;
                // If current height is less than rightMax, we can trap water here
                if (height[right] < rightMax) {
                    result += rightMax - height[right];
                } else {
                    // Updating rightMax if we find a taller bar
                    rightMax = height[right];
                }
            }
        }
        return result;
    }
};