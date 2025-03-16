class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0;
        long long right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars; // Maximum possible time
        while (left < right) {
            long long mid = left + (right - left) / 2;
            // Check if we can repair all cars within 'mid' time
            if (canRepairAllCars(ranks, cars, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
private:
    bool canRepairAllCars(vector<int>& ranks, int cars, long long time) {
        long long totalCarsRepaired = 0;
        for (int rank : ranks) {
            // For each mechanic,first calculating how many cars they can repair within 'time'
            //n = sqrt(time / r)
            long long carsRepaired = sqrt(time / rank);
            totalCarsRepaired += carsRepaired;
            // If we've already reached the target number of cars, return true
            if (totalCarsRepaired >= cars) {
                return true;
            }
        }
        return false;
    }
};