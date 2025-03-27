class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int dominant = -1;
        int n = nums.size();
        for (auto& [num, count] : freq) {
            if (count > n / 2) {
                dominant = num;
                break;
            }
        }
        if (dominant == -1) return -1;
        int leftCount = 0, totalDominantCount = freq[dominant];
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) {
                leftCount++;
            }
            int leftSize = i + 1;
            int rightSize = n - leftSize;
            if (leftCount * 2 > leftSize && 
                (totalDominantCount - leftCount) * 2 > rightSize) {
                return i;
            }
        }
        return -1;
    }
};