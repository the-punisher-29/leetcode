class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Use unordered set for O(1) lookup
        unordered_set<int> seen;
        
        for (int num : arr) {
            // Check if double of current number exists
            if (seen.count(num * 2) > 0) {
                return true;
            }
            
            // Check if half of current number exists 
            // (only for even numbers to avoid integer division issues)
            if (num % 2 == 0 && seen.count(num / 2) > 0) {
                return true;
            }
            
            // Add current number to set
            seen.insert(num);
        }
        
        return false;
    }
};