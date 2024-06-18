class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalLength = nums1.size() + nums2.size();
    if (totalLength % 2 == 1) {
        return findKthElement(nums1, 0, nums2, 0, totalLength / 2 + 1);
    } else {
        return (findKthElement(nums1, 0, nums2, 0, totalLength / 2) +
                findKthElement(nums1, 0, nums2, 0, totalLength / 2 + 1)) / 2.0;
    }
}

int findKthElement(const vector<int>& nums1, int i, const vector<int>& nums2, int j, int k) {
    if (i >= nums1.size()) return nums2[j + k - 1];
    if (j >= nums2.size()) return nums1[i + k - 1];
    if (k == 1) return min(nums1[i], nums2[j]);

    int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
    int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;

    if (midVal1 < midVal2) {
        return findKthElement(nums1, i + k / 2, nums2, j, k - k / 2);
    } else {
        return findKthElement(nums1, i, nums2, j + k / 2, k - k / 2);
    }
        
    }
};