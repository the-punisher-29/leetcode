class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Initialize all children with 1 candy 
        // Left to right pass
        // If current child has higher rating than left neighbor,
        // give them one more candy than the left neighbor
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        } 
        // Right to left pass
        // If current child has higher rating than right neighbor,
        // ensure they have more candies than the right neighbor
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        int total = 0;
        for (int candy : candies) {
            total += candy;
        }
        
        return total;
    }
};