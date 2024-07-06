class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long count = 0;
        vector<int> masks(1024, 0); // Store the count of bitwise masks
        masks[0] = 1; // Empty substring is wonderful
        int curr_mask = 0;
        
        for (char c : word) {
            curr_mask ^= (1 << (c - 'a')); // Update the current mask
            count += masks[curr_mask]; // Count the wonderful substrings
            
            // Count the wonderful substrings with at most one character having odd count
            for (int k = 0; k < 10; ++k) {
                int mask = curr_mask ^ (1 << k);
                count += masks[mask];
            }
            
            masks[curr_mask]++; // Update the count of the current mask
        }
        
        return count;
    }
};