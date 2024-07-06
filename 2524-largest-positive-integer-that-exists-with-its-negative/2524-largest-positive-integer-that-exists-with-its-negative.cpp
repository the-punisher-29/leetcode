
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int largestK = -1;

        for (int num : nums) {
            if (num > 0 && numSet.find(-num) != numSet.end()) {
                largestK =max(largestK, num);
            }
        }

        return largestK;
    }
};