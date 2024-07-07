class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drankBottles = numBottles;  // Initially, we can drink all the bottles we have
        int emptyBottles = numBottles;  // After drinking, we have this many empty bottles
        
        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;  // Exchange empty bottles for new full ones
            drankBottles += newBottles;  // Drink the new bottles
            
            // Update the number of empty bottles:
            // Remaining empties that couldn't be exchanged + newly emptied bottles
            emptyBottles = (emptyBottles % numExchange) + newBottles;
        }
        
        return drankBottles;
    }
};