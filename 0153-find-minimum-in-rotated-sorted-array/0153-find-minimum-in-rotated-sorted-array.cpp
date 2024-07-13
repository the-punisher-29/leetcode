class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If the middle element is greater than the rightmost element,
            // the minimum is in the right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Otherwise, the minimum is in the left half or is the middle element
            else {
                right = mid;
            }
        }
        
        // When left == right, we've found the minimum element
        return nums[left];
    }
};