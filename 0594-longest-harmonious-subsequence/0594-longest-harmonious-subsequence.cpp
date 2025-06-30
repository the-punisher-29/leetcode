class Solution{
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxLength = 0;
        
        for (int num : nums) {
            count[num]++;
            
            // Check if we can form harmonious subsequence with num-1 and num
            if (count.find(num - 1) != count.end()) {
                maxLength = max(maxLength, count[num] + count[num - 1]);
            }
            
            // Check if we can form harmonious subsequence with num and num+1
            if (count.find(num + 1) != count.end()) {
                maxLength = max(maxLength, count[num] + count[num + 1]);
            }
        }
        
        return maxLength;
    }
};