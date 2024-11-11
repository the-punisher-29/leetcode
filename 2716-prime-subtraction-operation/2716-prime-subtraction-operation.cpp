class Solution {
private:
    // Function to find all prime numbers less than n using Sieve of Eratosthenes
    vector<int> findPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;
        
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }
    
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        // Find all primes less than maximum element
        vector<int> primes = findPrimes(1000);
        
        // Process from left to right
        for (int i = n - 2; i >= 0; i--) {
            // If current number is already less than next number, continue
            if (nums[i] < nums[i + 1]) continue;
            
            // Find suitable prime to subtract
            bool found = false;
            for (int p : primes) {
                if (p < nums[i] && nums[i] - p < nums[i + 1]) {
                    nums[i] -= p;
                    found = true;
                    break;
                }
            }
            
            // If no suitable prime found
            if (!found) return false;
        }
        
        // Check if array is strictly increasing
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) return false;
        }
        
        return true;
    }
};