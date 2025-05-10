class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zeros1 = 0, zeros2 = 0;
        for (int num : nums1) {
            if (num == 0) zeros1++;
            sum1 += num;
        }
        for (int num : nums2) {
            if (num == 0) zeros2++;
            sum2 += num;
        }
        long long minPossibleSum1 = sum1 + zeros1;
        long long minPossibleSum2 = sum2 + zeros2;
        // Case 1: If min possible sum1 > min possible sum2 AND array2 has no zeros
        // We can't increase sum2 to match sum1
        if (minPossibleSum1 > minPossibleSum2 && zeros2 == 0) {
            return -1;
        }
        // Case 2: If min possible sum2 > min possible sum1 AND array1 has no zeros
        // We can't increase sum1 to match sum2
        if (minPossibleSum2 > minPossibleSum1 && zeros1 == 0) {
            return -1;
        }
        return max(minPossibleSum1, minPossibleSum2);
    }
};