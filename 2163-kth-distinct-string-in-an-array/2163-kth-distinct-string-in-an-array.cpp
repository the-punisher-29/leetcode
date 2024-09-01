class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;
        for (const string& s : arr) {
            count[s]++;
        }
        // Find the kth distinct string
        int distinctCount = 0;
        for (const string& s : arr) {
            if (count[s] == 1) {
                distinctCount++;
                if (distinctCount == k) {
                    return s;
                }
            }
        }
        return "";
    }
};