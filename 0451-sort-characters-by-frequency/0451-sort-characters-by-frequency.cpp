class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> fc;
        for(auto c : s) {
            fc[c]++;
        }
        
        // max heap to sort characters based on frequency--new cmp shit ---rem this
        auto cmp = [](pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        
        for(auto &pair : fc) {
            pq.push(pair);
        }
        string res;
        while(!pq.empty()) {
            auto [ch, freq] = pq.top();
            pq.pop();
            res.append(freq, ch);
        }
        
        return res;
    }
};