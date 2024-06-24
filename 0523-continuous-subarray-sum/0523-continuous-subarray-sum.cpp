class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Map to store the modulo and its earliest index
        unordered_map<int, int> prefix_sum_mod_map;
        prefix_sum_mod_map[0] = -1; // Base case for subarrays starting from index 0
        
        int prefix_sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            int mod_value = prefix_sum % k;
            
            // Make sure mod_value is positive
            if (mod_value < 0) mod_value += k;
            
            if (prefix_sum_mod_map.find(mod_value) != prefix_sum_mod_map.end()) {
                // Check if the subarray length is at least 2
                if (i - prefix_sum_mod_map[mod_value] > 1) {
                    return true;
                }
            } else {
                // Store the index for this modulo value
                prefix_sum_mod_map[mod_value] = i;
            }
        }
        
        return false;
    }
};
