class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result = {-1, -1};

        // Find the leftmost occurrence using lower_bound
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (left < n && nums[left] == target) {
            result[0] = left;
        }

        // Find the rightmost occurrence using upper_bound 
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if (right >= 0 && nums[right] == target) { // This check is crucial
            result[1] = right;
        } else if (result[0] != -1) { 
            // If only one occurrence exists, the left and right indices should be the same
            result[1] = result[0]; 
        } 

        return result;
    }
};

//typical approach
// private:
//     int binarySearch(vector<int>& nums, int target, bool leftmost) {
//         int left = 0;
//         int right = nums.size();
        
//         while (left < right) {
//             int mid = left + (right - left) / 2;
            
//             if (nums[mid] > target || (leftmost && nums[mid] == target)) {
//                 right = mid;
//             } else {
//                 left = mid + 1;
//             }
//         }
        
//         return left;
//     }