class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            // Update the minimum price seen so far
            minPrice = min(minPrice, price);
            
            // Update the maximum profit if selling at current price
            maxProfit = max(maxProfit, price - minPrice);
        }
        
        return maxProfit;
    }
};