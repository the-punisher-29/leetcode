class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result = prices;
        
        // Nested loop to find the first smaller or equal element to the right
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // If found a smaller or equal element
                if (prices[j] <= prices[i]) {
                    // Apply discount
                    result[i] = prices[i] - prices[j];
                    break;  // Apply only the first such discount
                }
            }
        }
        
        return result;
    }
};