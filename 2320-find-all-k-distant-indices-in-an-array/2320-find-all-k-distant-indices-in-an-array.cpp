class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool isKDistant = false;
            int left = max(0, i - k);
            int right = min(n - 1, i + k);
            for (int j = left; j <= right; j++) {
                if (nums[j] == key) {
                    isKDistant = true;
                    break;
                }
            }
            if (isKDistant) {
                result.push_back(i);
            }
        }
        return result;
    }
};