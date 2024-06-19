class Solution {
public:
    double myPow(double x, int n) {
        double op=1;
        long long p=n;//handling overflow
        if(p<0){
            x=1/x;
            p=-p;
        }
        while(p>0){
            if(p%2==1){
                op=op*x;
            }
            x*=x;
            p=p/2;
        }
        return op;
    }
};