class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreq;
        int count = 0;
        int sum = 0;
        
        sumFreq[0] = 1;  // Initialize with 0 sum having frequency 1
        
        for (int num : nums) {
            sum += num;
            
            if (sumFreq.find(sum - k) != sumFreq.end()) {
                count += sumFreq[sum - k];
            }
            
            sumFreq[sum]++;
        }
        
        return count;
    }
};