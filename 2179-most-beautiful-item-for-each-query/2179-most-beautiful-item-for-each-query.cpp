class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // First, sort items by price
        sort(items.begin(), items.end());
        
        // Keep track of maximum beauty seen so far for each price point
        // This handles cases where we have multiple items with same price
        int maxBeautySoFar = 0;
        vector<pair<int, int>> priceToMaxBeauty;  // {price, maxBeauty}
        
        for (const auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            maxBeautySoFar = max(maxBeautySoFar, beauty);
            
            // If we have previous entries and last price is same as current,
            // update with max beauty
            if (!priceToMaxBeauty.empty() && priceToMaxBeauty.back().first == price) {
                priceToMaxBeauty.back().second = maxBeautySoFar;
            } else {
                priceToMaxBeauty.push_back({price, maxBeautySoFar});
            }
        }
        
        // Process each query
        vector<int> answer(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int query = queries[i];
            
            // Binary search to find the largest price <= query
            auto it = upper_bound(priceToMaxBeauty.begin(), priceToMaxBeauty.end(), 
                                make_pair(query, INT_MAX));
            
            if (it == priceToMaxBeauty.begin()) {
                // No item with price <= query
                answer[i] = 0;
            } else {
                // Get the maximum beauty for the largest price <= query
                --it;
                answer[i] = it->second;
            }
        }
        
        return answer;
    }
};