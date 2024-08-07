class Solution {
public:
    int pivotInteger(int n) {
        int y = n * (n + 1) / 2;
        int x = sqrt(y);
        // Check if x is indeed the pivot
        return x * x == y ? x : -1;
    }
};