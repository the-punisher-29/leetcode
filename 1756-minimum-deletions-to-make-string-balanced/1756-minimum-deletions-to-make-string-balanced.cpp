class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;
        int deletions = 0;
        
        for (char c : s) {
            if (c == 'a') {
                // If we encounter 'a', we have two choices:
                // 1. Delete this 'a'
                // 2. Delete all previous 'b's
                // We choose the minimum of these two
                deletions = min(deletions + 1, bCount);
            } else {
                // If we encounter 'b', just increment the count
                bCount++;
            }
        }
        
        return deletions;
    }
};