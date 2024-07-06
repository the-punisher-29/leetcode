class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (tickets[i] > 0) {
                time++;
                tickets[i]--;
                if (tickets[i] > 0) {
                    q.push(i);
                }
            }
            if (i == k && tickets[i] == 0) {
                break;
            }
        }
        return time;
    }
};