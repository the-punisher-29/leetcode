class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) {
            return 1;
        }
        
        // Recursive call
        int x = findTheWinner(n - 1, k);
        
        // Calculate the new position
        return (x + k - 1) % n + 1;
    }
};