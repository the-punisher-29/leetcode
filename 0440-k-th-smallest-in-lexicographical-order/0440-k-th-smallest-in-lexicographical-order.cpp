class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1; // Since we start with 1, we need to find the (k-1)th number after 1
        
        while (k > 0) {
            long long steps = calSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }
    
private:
    long long calSteps(long long n, long long n1, long long n2) {
        long long steps = 0;
        while (n1 <= n) {
            steps += min(n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};