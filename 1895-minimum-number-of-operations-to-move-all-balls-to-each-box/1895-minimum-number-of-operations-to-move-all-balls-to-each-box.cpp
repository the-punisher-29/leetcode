class Solution {
public:
   vector<int> minOperations(string boxes) {
       int n = boxes.length();
       vector<int> answer(n);
       for(int i = 0; i < n; i++) {
           int moves = 0;
           for(int j = 0; j < n; j++) {
               if(i != j && boxes[j] == '1') {
                   moves += abs(i - j);
               }
           }
           answer[i] = moves;
       }
       return answer;
   }
};