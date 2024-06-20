class Solution {
public:
    // Helper function to check if a given substring is a palindrome
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    // Backtracking function to find all palindrome partitions
    void backtrack(vector<vector<string>> &result, vector<string> &currentPartition, const string &s, int start) {
        // If we have reached the end of the string, add the current partition to the result
        if (start == s.size()) {
            result.push_back(currentPartition);
            return;
        }

        // Try to partition the string at every possible position
        for (int end = start; end < s.size(); end++) {
            // If the substring s[start:end+1] is a palindrome, proceed with this partition
            if (isPalindrome(s, start, end)) {
                // Add the current palindrome substring to the current partition
                currentPartition.push_back(s.substr(start, end - start + 1));
                // Recur for the remaining substring
                backtrack(result, currentPartition, s, end + 1);
                // Backtrack to explore other partitions
                currentPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPartition;
        backtrack(result, currentPartition, s, 0);
        return result;
    }
};
