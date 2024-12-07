class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, mid, maxOperations)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    bool canDivide(vector<int>& nums, int penalty, int maxOperations) {
        int operations = 0;
        for (int bag : nums) {
            // Calculate operations needed to divide this bag
            operations += (bag - 1) / penalty;
        }
        return operations <= maxOperations;
    }
};