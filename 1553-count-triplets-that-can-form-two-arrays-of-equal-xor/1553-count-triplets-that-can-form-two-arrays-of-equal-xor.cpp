class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int> pXOR(n+1,0);
        for(int i=0;i<n;++i){
            pXOR[i+1]=pXOR[i]^arr[i];
        }
        int count =0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(pXOR[i]==pXOR[j+1]){
                    count+=(j-i);
                }
            }
        }
        return count;  
    }
};