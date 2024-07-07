class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zeros = 0;
        int ones = 0;

         // Count the number of zeros and ones in the string
        for (char c : s) {
             if (c == '0') {
                 zeros++;
             } else {
                 ones++;
             }
         }

         // Form the maximum odd binary number using the counts of zeros and ones
         return string(ones - 1, '1') + string(zeros, '0') + '1';
         }
};