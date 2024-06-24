class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> countMap;
        int maxLength = 0;
        int count = 0;

        countMap[0] = -1; // Initialize map with 0 count at index -1

        for (int i = 0; i < nums.size(); i++) {
            // Update count based on the value of nums[i]
            count += (nums[i] == 1 ? 1 : -1);

            // If the count is already present in the map, update max length
            if (countMap.find(count) != countMap.end()) {
                maxLength = max(maxLength, i - countMap[count]);
            } else {
                // If count is encountered for the first time, store its index
                countMap[count] = i;
            }
        }

        return maxLength;
    }
};