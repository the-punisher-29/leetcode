class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        for (int i = 0; i < n; i++) indices[i] = i;
        
        // Sort robots by position
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        stack<int> st;
        
        for (int i : indices) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                // Only process collisions if there are robots moving right
                if (!st.empty()) {
                    while (!st.empty() && healths[i] > 0) {
                        int j = st.top();
                        if (healths[j] > healths[i]) {
                            healths[j]--;
                            healths[i] = 0;
                            break;
                        } else if (healths[j] < healths[i]) {
                            healths[i]--;
                            healths[j] = 0;
                            st.pop();
                        } else {
                            healths[i] = 0;
                            healths[j] = 0;
                            st.pop();
                            break;
                        }
                    }
                }
                // If this robot survives, don't add it to the stack
                // as it's moving left and won't collide with future robots
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        
        return result;
    }
};