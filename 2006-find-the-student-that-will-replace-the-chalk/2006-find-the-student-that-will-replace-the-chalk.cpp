class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (int i = 0; i < chalk.size(); i++) {
            sum += chalk[i];
        }
        
        // Optimize by taking modulo of k with sum
        k %= sum;
        
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        // This line should never be reached
        return -1;
    }
};