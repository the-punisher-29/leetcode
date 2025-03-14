class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxArea = 0;
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            // When we find a bar shorter than what's on top of the stack,
            // we pop and calculate areas with the popped bar as the limiting height
            while (!s.empty() && h < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                // smaller bar to the position before the current smaller bar
                int width = s.empty() ? i : (i - s.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }
        
        return maxArea;
    }
};