class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int result = 0;
        
        for (int j = 1; j < n - 1; j++) {
            int leftSmaller = 0, leftLarger = 0;
            int rightSmaller = 0, rightLarger = 0;
            
            // Count smaller and larger elements to the left of j
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) leftSmaller++;
                else if (rating[i] > rating[j]) leftLarger++;
            }
            
            // Count smaller and larger elements to the right of j
            for (int k = j + 1; k < n; k++) {
                if (rating[k] < rating[j]) rightSmaller++;
                else if (rating[k] > rating[j]) rightLarger++;
            }
            
            // Calculate valid teams with j as the middle element
            result += leftSmaller * rightLarger + leftLarger * rightSmaller;
        }
        
        return result;
    }
};