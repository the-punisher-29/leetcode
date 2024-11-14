class Solution {
public:
    // Helper function to check if distribution is possible with given maximum value
    bool canDistribute(int maxQuantity, int n, vector<int>& quantities) {
        int storesNeeded = 0;
        for (int q : quantities) {
            // For each product type, calculate how many stores we need
            // if we can't give more than maxQuantity to each store
            storesNeeded += (q + maxQuantity - 1) / maxQuantity;
            // Early exit if we need too many stores
            if (storesNeeded > n) return false;
        }
        return storesNeeded <= n;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        // Binary search on the answer
        // Minimum possible answer is 1 (can't give 0 products)
        int left = 1;
        // Maximum possible answer is the maximum quantity
        // (when we have to put all products of one type in one store)
        int right = *max_element(quantities.begin(), quantities.end());
        
        // Binary search for the smallest valid maximum quantity
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canDistribute(mid, n, quantities)) {
                // If we can distribute with this maximum,
                // try to find a smaller maximum
                right = mid;
            } else {
                // If we can't distribute with this maximum,
                // we need a larger maximum
                left = mid + 1;
            }
        }
        
        return left;
    }
};