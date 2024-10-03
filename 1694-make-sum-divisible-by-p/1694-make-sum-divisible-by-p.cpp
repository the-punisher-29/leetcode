///prefix summm
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int target = total_sum % p;
        if (target == 0) return 0;
        
        unordered_map<int, int> prefix_sum_map;
        prefix_sum_map[0] = -1;
        
        int min_length = n;
        long long current_sum = 0;
        
        for (int i = 0; i < n; i++) {
            current_sum += nums[i];
            int remainder = current_sum % p;
            
            int complement = (remainder - target + p) % p;
            if (prefix_sum_map.find(complement) != prefix_sum_map.end()) {
                min_length = min(min_length, i - prefix_sum_map[complement]);
            }
            
            prefix_sum_map[remainder] = i;
        }
        
        return min_length < n ? min_length : -1;
    }
};