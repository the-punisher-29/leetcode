class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            maxArea = max(maxArea, maxAreaInHistogram(heights));
        }

        return maxArea;
    }

private:
    int maxAreaInHistogram(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        int i = 0;

        while (i < n) {
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i++);
            } else {
                int top = st.top();
                st.pop();
                maxArea = max(maxArea, heights[top] * (st.empty() ? i : i - st.top() - 1));
            }
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            maxArea = max(maxArea, heights[top] * (st.empty() ? i : i - st.top() - 1));
        }

        return maxArea;
    }
};