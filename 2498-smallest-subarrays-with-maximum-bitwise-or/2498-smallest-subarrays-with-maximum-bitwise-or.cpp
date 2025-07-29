class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int size = nums.size();
        vector<int> lastIndex(32, -1);
        vector<int> result(size);
        for (int i = size - 1; i >= 0; --i) {
            int subarraySize = 1;
            for (int bit = 0; bit < 32; ++bit) {
                if ((nums[i] >> bit) & 1) {
                    lastIndex[bit] = i;
                } else if (lastIndex[bit] != -1) {
                    subarraySize = max(subarraySize, lastIndex[bit] - i + 1);
                }
            }
            result[i] = subarraySize;
        }
        return result;
    }
};