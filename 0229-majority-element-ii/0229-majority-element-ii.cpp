class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> result;
        int threshold = nums.size() / 3;
        
        // Count occurrences
        for (int num : nums) {
            count[num]++;
        }
        
        // Find elements above threshold
        for (auto& [num, freq] : count) {
            if (freq > threshold) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};