class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        int ind=0;
        for(int i=1;i<=n/2;++i){
            res[ind++]=i;
            res[ind++]=-i;
        }
        return res;
        
    }
};