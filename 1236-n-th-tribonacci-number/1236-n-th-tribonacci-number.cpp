class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        else if(n==1 or n==2) return 1;
        else{
            int t0=0;
            int t1=1;
            int t2=1;
            for(int i=3;i<=n;++i){
                int tn=t0+t1+t2;
                t0=t1;
                t1=t2;
                t2=tn;
            }
            return t2;
        }
    }
};