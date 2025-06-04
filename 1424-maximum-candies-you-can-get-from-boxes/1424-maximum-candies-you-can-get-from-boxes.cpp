class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> haveBox(n, false);
        vector<bool> haveKey(n, false);
        vector<bool> opened(n, false);
        //stores boxes we can currently open
        queue<int> q;
        for (int box : initialBoxes) {
            haveBox[box] = true;
            // If box is open or we have key for it, we can process it
            if (status[box] == 1) {
                q.push(box);
            }
        }
        int totalCandies = 0;
        while (!q.empty()) {
            int currentBox = q.front();
            q.pop();
            // Skip if already opened
            if (opened[currentBox]) continue;
            // Mark as opened and collect candies
            opened[currentBox] = true;
            totalCandies += candies[currentBox];
            // Collect all keys from this box
            for (int key : keys[currentBox]) {
                haveKey[key] = true;
                // If we have this box and now have its key, we can open it
                if (haveBox[key] && !opened[key]) {
                    q.push(key);
                }
            }
            for (int box : containedBoxes[currentBox]) {
                haveBox[box] = true;
                // If box is open or we have key for it, we can process it
                if (!opened[box] && (status[box] == 1 || haveKey[box])) {
                    q.push(box);
                }
            }
        }
        return totalCandies;
    }
};