class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int prpst = 0;
        int cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                prpst = num;
            }
            if (num == prpst) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return prpst;
    }
};