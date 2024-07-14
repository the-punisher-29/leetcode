class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEatAll(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canEatAll(const vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile - 1) / k + 1;
        }
        return hours <= h;
    }
};