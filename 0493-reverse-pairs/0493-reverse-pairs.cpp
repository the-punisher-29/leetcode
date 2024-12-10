class Solution {
private:
    int mergeSort(vector<int>& nums, int left, int right) {
        // Base case: if subarray has 0 or 1 element, no reverse pairs
        if (left >= right) return 0;
        
        // Divide the array
        int mid = left + (right - left) / 2;
        
        // Recursively count reverse pairs in left and right subarrays
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        
        // Count cross-array reverse pairs
        count += countCrossPairs(nums, left, mid, right);
        
        // Merge the subarrays
        merge(nums, left, mid, right);
        
        return count;
    }
    
    int countCrossPairs(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        // Count reverse pairs across the two subarrays
        for (int i = left; i <= mid; i++) {
            // Find the first index where nums[i] <= 2 * nums[j]
            while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        return count;
    }
    
    void merge(vector<int>& nums, int left, int mid, int right) {
        // Temporary vector to store merged result
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        
        // Merge two sorted subarrays
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        // Copy remaining elements from left subarray
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        
        // Copy remaining elements from right subarray
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        
        // Copy back to original array
        for (int p = 0; p < k; p++) {
            nums[left + p] = temp[p];
        }
    }
    
public:
    int reversePairs(vector<int>& nums) {
        // Handle empty array case
        if (nums.empty()) return 0;
        
        // Start merge sort and count reverse pairs
        return mergeSort(nums, 0, nums.size() - 1);
    }
};