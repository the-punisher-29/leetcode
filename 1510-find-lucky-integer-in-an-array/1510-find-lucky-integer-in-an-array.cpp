class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }   
        int maxLucky = -1;
        for (auto& pair : freq) {
            int value = pair.first;
            int frequency = pair.second;
            // If frequency equals value, it's a lucky number
            if (frequency == value) {
                maxLucky = max(maxLucky, value);
            }
        }
        
        return maxLucky;
    }
};