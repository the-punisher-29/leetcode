class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int ssum = 0;
        int dsum = 0;
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        
        for (int num : nums) {
            if (num >= 1 && num <= 9) {
                ssum += num;
            } else if (num >= 10 && num <= 99) {
                dsum+= num;
            }
        }
        int ssumrem = tsum - ssum;
        int dsumrem = tsum - dsum;
        if (ssum > ssumrem || dsum > dsumrem) {
            return true;
        }
        return false;
    }
};