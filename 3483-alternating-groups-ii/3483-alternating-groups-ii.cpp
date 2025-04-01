class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int length = colors.size();
        int result = 0;
        //bounds of sliding wi 
        int left = 0;
        int right = 1;

        while (right < length) {
            if (colors[right] == colors[right - 1]) {
                //if same,reset
                left = right;
                right++;
                continue;
            }
            //wrna move right
            right++;
            if (right - left < k) continue;
            //slide 
            result++;
            left++;
        }
        return result;
    }
};