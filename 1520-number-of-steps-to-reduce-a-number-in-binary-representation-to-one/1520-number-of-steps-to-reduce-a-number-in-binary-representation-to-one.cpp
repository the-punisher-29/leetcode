// class Solution {
// public:
//     int numSteps(string s) {
//         int num=stoi(s,NULL,2);
//         int steps=0;
//         while(num!=1){
//             if(num%2==0){
//                 num/=2;
//             }
//             else{
//                 num+=1;
//             }
//             steps++;
//         }
//         return steps;
//     }
// };///overflow issue

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        for (int i = s.length() - 1; i > 0; --i) {
            if (s[i] - '0' + carry == 1) {
                // If the bit is 1, adding 1 turns it into 0 with carry over
                carry = 1;
                steps += 2; // 1 for turning 1 to 0, 1 for the division step
            } else {
                // If the bit is 0, just divide
                steps += 1;
            }
        }
        // If there is carry left, add one step for the most significant bit
        if (carry == 1) {
            steps += 1;
        }
        return steps;
    }
};
