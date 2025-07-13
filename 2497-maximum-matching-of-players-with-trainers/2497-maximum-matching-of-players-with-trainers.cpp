class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int matches = 0;
        int trainersIndex = 0;
        for (int playerStrength : players) {
            while (trainersIndex < trainers.size() && trainers[trainersIndex] < playerStrength) {
                trainersIndex++;
            }
            if (trainersIndex < trainers.size()) {
                matches++;
                trainersIndex++;
            }
        }
        return matches;
    }
};