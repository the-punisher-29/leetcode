class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfied = 0;
        int additional = 0;
        
        // Calculate initially satisfied customers and potential additional customers
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
            } else {
                additional += customers[i];
            }
        }
        
        // Initial window
        int current_additional = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                current_additional += customers[i];
            }
        }
        
        int max_additional = current_additional;
        
        // Slide the window
        for (int i = minutes; i < n; i++) {
            if (grumpy[i - minutes] == 1) {
                current_additional -= customers[i - minutes];
            }
            if (grumpy[i] == 1) {
                current_additional += customers[i];
            }
            max_additional = max(max_additional, current_additional);
        }
        
        return satisfied + max_additional;
    }
};