class Solution {
public:
   vector<int> minOperations(string bxs) {
       int n=bxs.length();
       vector<int> ans(n);
       for(int i = 0; i<n; i++){
           int moves=0;
           for(int j=0; j<n; j++) {
               if(i!=j && bxs[j]=='1') {
                   moves +=abs(i-j);
               }
           }
           ans[i] = moves;
       }
       return ans;
   }
};