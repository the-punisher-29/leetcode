class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        
        // Generate palindromes by length
        for (int len = 1; count < n; len++) {
            // Generate all palindromes of length 'len'
            vector<long long> palindromes = generatePalindromes(len);
            
            for (long long palindrome : palindromes) {
                if (count >= n) break;
                
                // Check if this palindrome is also a palindrome in base-k
                if (isPalindromeInBaseK(palindrome, k)) {
                    sum += palindrome;
                    count++;
                }
            }
        }
        
        return sum;
    }
    
private:
    vector<long long> generatePalindromes(int len) {
        vector<long long> result;
        
        if (len == 1) {
            for (int i = 1; i <= 9; i++) {
                result.push_back(i);
            }
            return result;
        }
        
        int halfLen = (len + 1) / 2;
        long long start = pow(10, halfLen - 1);
        long long end = pow(10, halfLen) - 1;
        
        for (long long i = start; i <= end; i++) {
            string half = to_string(i);
            string palindrome = half;
            
            // Add the reverse of the first half (excluding middle for odd length)
            for (int j = len % 2 == 0 ? half.length() - 1 : half.length() - 2; j >= 0; j--) {
                palindrome += half[j];
            }
            
            result.push_back(stoll(palindrome));
        }
        
        return result;
    }
    
    bool isPalindromeInBaseK(long long num, int k) {
        vector<int> digits;
        long long temp = num;
        
        // Convert to base-k
        while (temp > 0) {
            digits.push_back(temp % k);
            temp /= k;
        }
        
        // Check if palindrome
        int left = 0, right = digits.size() - 1;
        while (left < right) {
            if (digits[left] != digits[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};