#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        int result = -1;
        for (int len = n; len >= 1; --len) {
            unordered_map<string, int> substringCount;
            for (int i = 0; i <= n - len; ++i) {
                string sub = s.substr(i, len);
                if (isSpecial(sub)) {
                    substringCount[sub]++;
                    if (substringCount[sub] >= 3) {
                        result = len; // Update the maximum length
                        return result; // Return immediately since we are iterating in descending order
                    }
                }
            }
        }
        return result;
    }
private:
    bool isSpecial(const string& str) {
        char firstChar = str[0];
        for (char c : str) {
            if (c != firstChar) return false;
        }
        return true;
    }
};
