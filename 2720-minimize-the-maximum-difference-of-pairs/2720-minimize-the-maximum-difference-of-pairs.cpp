class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums[0];
        while (left < right) {
            int mid = (left + right) / 2;   
            if (countPairs(nums, mid) >= p) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    int countPairs(vector<int>& nums, int maxDiff) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                count++;
                i++; // Skip next element
            }
        }
        return count;
    }
};