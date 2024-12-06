class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Convert banned to a set for O(1) lookup
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        
        // Track chosen numbers and current sum
        int count = 0;
        int currentSum = 0;
        
        // Iterate through numbers from 1 to n
        for (int num = 1; num <= n; num++) {
            // Skip banned numbers
            if (bannedSet.count(num)) continue;
            
            // Check if adding this number exceeds maxSum
            if (currentSum + num > maxSum) break;
            
            // Add the number
            currentSum += num;
            count++;
        }
        
        return count;
    }
};