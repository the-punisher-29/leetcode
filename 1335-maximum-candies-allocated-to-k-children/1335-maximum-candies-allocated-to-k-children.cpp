typedef long long ll;
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxPile = 0;
        for (int pile : candies) {
            maxPile = max(maxPile, pile);
        }
        ll sum = 0;
        for (int pile : candies) {
            sum += pile;
        }
        if (sum < k) return 0;
        int left = 1;
        int right = maxPile;
        int result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAllocate(candies, k, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
private:
    bool canAllocate(vector<int>& candies, long long k, int candiesPerChild) {
        if (candiesPerChild == 0) return true;
        ll childrenCount = 0;
        for (int pile : candies) {
            childrenCount += pile / candiesPerChild;
            if (childrenCount >= k) {
                return true;
            }
        }
        return childrenCount >= k;
    }
};