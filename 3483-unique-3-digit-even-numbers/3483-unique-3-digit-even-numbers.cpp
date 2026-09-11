class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int d : digits) freq[d]++;

        int count = 0;

        for (int h = 1; h <= 9; h++) {
            for (int t = 0; t <= 9; t++) {
                for (int u = 0; u <= 8; u += 2) {
                    // tally how many of each digit value this triple needs
                    int need[10] = {0};
                    need[h]++;
                    need[t]++;
                    need[u]++;

                    bool feasible = true;
                    for (int digit = 0; digit <= 9; digit++) {
                        if (need[digit] > freq[digit]) {
                            feasible = false;
                            break;
                        }
                    }

                    if (feasible) count++;
                }
            }
        }

        return count;
    }
};