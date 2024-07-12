class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int points = 0;
        string first, second;
        char a, b;
        
        // Determine which substring to remove first based on points
        if (x >= y) {
            first = "ab";
            second = "ba";
            a = 'a';
            b = 'b';
        } else {
            first = "ba";
            second = "ab";
            a = 'b';
            b = 'a';
            swap(x, y);
        }
        
        // First pass: remove the higher-value substring
        string remaining;
        for (char c : s) {
            if (!remaining.empty() && remaining.back() == a && c == b) {
                remaining.pop_back();
                points += x;
            } else {
                remaining.push_back(c);
            }
        }
        
        // Second pass: remove the lower-value substring
        s = remaining;
        remaining.clear();
        for (char c : s) {
            if (!remaining.empty() && remaining.back() == b && c == a) {
                remaining.pop_back();
                points += y;
            } else {
                remaining.push_back(c);
            }
        }
        
        return points;
    }
};