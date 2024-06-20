class Solution {
public:
    int mySqrt(int x) {
        double pow=0.5;
        if(x==0) return 0;
        long long res=x;//overflow avoidance
        //newton's method
        while(res*res>x){
            res=(res+x/res)/2;
        }
        return res;
    }
};