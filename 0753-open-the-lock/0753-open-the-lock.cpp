class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadends_set(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({"0000", 0});

        while (!q.empty()) {
            auto [current, distance] = q.front();
            q.pop();
            if (current == target) {
                return distance;
            }
            if (deadends_set.count(current) || visited.count(current)) {
                continue;
            }
            visited.insert(current);
            for (int i = 0; i < 4; ++i) {
                for (int j = -1; j <= 1; j += 2) {
                    string new_combination = current;
                    new_combination[i] = ((new_combination[i] - '0') + j + 10) % 10 + '0';
                    if (!visited.count(new_combination) && !deadends_set.count(new_combination)) {
                        q.push({new_combination, distance + 1});
                    }
                }
            }
        }
        return -1;
    }
};