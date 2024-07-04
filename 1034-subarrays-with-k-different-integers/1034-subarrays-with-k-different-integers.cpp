class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
private:
    int atMost(vector<int>& nums, int k) {
        int count = 0;
        int distinct = 0;
        unordered_map<int, int> freq;
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // If the current element is not in the window, increment distinct
            if (freq[nums[right]] == 0) {
                distinct++;
            }
            
            // Increment the frequency of the current element
            freq[nums[right]]++;
            
            // If the number of distinct elements exceeds k, move the left pointer
            while (distinct > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    distinct--;
                }
                left++;
            }
            
            // If the number of distinct elements is at most k, update the count
            count += right - left + 1;
        }
        
        return count;
    }
};