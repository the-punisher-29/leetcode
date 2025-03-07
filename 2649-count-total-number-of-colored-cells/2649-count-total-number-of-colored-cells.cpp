class Solution {
public:
    long long coloredCells(int n) {

        //mathematical pattern
        //like it follows 1+4*(1+2+3+.....+(n-1))
        //....2n^2-2n+1
        //so i return

        //return 2*n*n-2*n+1;
        
        //pverflow issue so,LL
        return 2LL*n*n-2LL*n+1;


        
    }
};