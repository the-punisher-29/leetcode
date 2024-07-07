class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int, int> freq;
        int maxVal = *max_element(nums.begin(), nums.end());
        
        for (int i = 0, j = 0, count = 0; j < nums.size(); j++) {
            freq[nums[j]]++;
            if (nums[j] == maxVal) count++;
            
            while (count >= k) {
                res += nums.size() - j;
                freq[nums[i]]--;
                if (nums[i] == maxVal) count--;
                i++;
            }
        }
        
        return res;
    }
};