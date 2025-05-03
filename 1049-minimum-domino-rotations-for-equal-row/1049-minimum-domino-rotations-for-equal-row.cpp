class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotations1 = checkRotations(tops[0], tops, bottoms, n);
        int rotations2 = checkRotations(bottoms[0], tops, bottoms, n);
        int minRotations = min(rotations1, rotations2);
        return minRotations == INT_MAX ? -1 : minRotations;
    }
    
private:
    int checkRotations(int target, vector<int>& tops, vector<int>& bottoms, int n) {
        // Counting rotations needed to make all tops = target
        int rotationsTop = 0;
        // Counting rotations needed to make all bottoms = target
        int rotationsBottom = 0;
        for (int i = 0; i < n; i++) {
            // If neither top nor bottom matches target, we can't succeed
            if (tops[i] != target && bottoms[i] != target) {
                return INT_MAX;
            }
            if (tops[i] != target && bottoms[i] == target) {
                rotationsTop++;
            }
            if (bottoms[i] != target && tops[i] == target) {
                rotationsBottom++;
            }
        }
        return min(rotationsTop, rotationsBottom);
    }
};