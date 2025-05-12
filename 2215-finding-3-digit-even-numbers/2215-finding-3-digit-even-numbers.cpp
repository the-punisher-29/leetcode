class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int digit : digits) {
            count[digit]++;
        }
        vector<int> result;
        // Try all possible three-digit numbers
        // First digit (hundreds place): 1-9 (can't be 0)
        for (int i = 1; i <= 9; i++) {
            if (count[i] == 0) continue;
            
            // Temporarily decrease count
            count[i]--;
            
            // Second digit (tens place): 0-9
            for (int j = 0; j <= 9; j++) {
                if (count[j] == 0) continue;
                
                count[j]--;
                
                // Third digit (ones place): only even digits (0, 2, 4, 6, 8)
                for (int k : {0, 2, 4, 6, 8}) {
                    if (count[k] == 0) continue;
                    
                    // Form the number: i*100 + j*10 + k
                    int num = i * 100 + j * 10 + k;
                    result.push_back(num);
                }
                
                // Restore count for second digit
                count[j]++;
            }
            
            // Restore count for first digit
            count[i]++;
        }
        
        // Sort the result (not necessary if we generated in order, but problem requires sorting)
        sort(result.begin(), result.end());
        
        return result;
    }
};