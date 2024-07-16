class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 = g.size();
        int n2 = s.size();
        
        // Sort both arrays in ascending order
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int contentChildren = 0;
        int i = 0; // Index for children
        int j = 0; // Index for cookies
        
        // Iterate through both arrays
        while (i < n1 && j < n2) {
            // If current cookie can satisfy current child
            if (s[j] >= g[i]) {
                contentChildren++;
                i++; // Move to next child
            }
            j++; // Move to next cookie
        }
        
        return contentChildren;
    }
};