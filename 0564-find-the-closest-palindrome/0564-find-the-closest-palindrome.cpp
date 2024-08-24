class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        int len = n.length();
        
        // Handle edge cases
        if (num <= 10) return to_string(num - 1);
        if (num == 11) return "9";
        if (isPowerOfTen(num)) return to_string(num - 1);
        if (isPowerOfTen(num + 1)) return to_string(num + 2);
        
        // Generate candidate palindromes
        vector<long long> candidates;
        candidates.push_back(pow(10, len - 1) - 1);  // All 9's
        candidates.push_back(pow(10, len) + 1);      // 100...001
        
        // Generate palindromes by mirroring left half
        long long leftHalf = stoll(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; i++) {
            string left = to_string(leftHalf + i);
            string right = left.substr(0, len / 2);
            reverse(right.begin(), right.end());
            candidates.push_back(stoll(left + right));
        }
        
        // Find the closest palindrome
        long long closest = LLONG_MAX;
        long long result = 0;
        for (long long candidate : candidates) {
            if (candidate != num && abs(candidate - num) < abs(closest - num)) {
                closest = candidate;
                result = candidate;
            } else if (abs(candidate - num) == abs(closest - num) && candidate < result) {
                result = candidate;
            }
        }
        
        return to_string(result);
    }
    
private:
    bool isPowerOfTen(long long n) {
        return n == pow(10, to_string(n).length() - 1);
    }
};