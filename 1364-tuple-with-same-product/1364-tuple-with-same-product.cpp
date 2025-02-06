class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> pc;
        //all poss prod
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                pc[product]++;
            }
        }
        int result = 0;
        for(const auto& pair : pc) {
            int count = pair.second;
            if(count > 1) {
                result += 8 * (count * (count - 1) / 2);
            }
        }
        return result;
    }
};