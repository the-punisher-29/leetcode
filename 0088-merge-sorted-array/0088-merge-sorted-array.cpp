class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start from the end of the arrays
        int i = m - 1;    // Last element in nums1
        int j = n - 1;    // Last element in nums2
        int k = m + n - 1;// Last position in merged array
        
        // Merge from the end to avoid overwriting
        while (j >= 0) {
            // If nums1 still has elements and its last element is larger
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            // Otherwise, take element from nums2
            else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};