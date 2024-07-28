class Solution {
public:
    int nonSpecialCount(int l, int r) {
        // int cnt=0;
        // int gd=0;
        // for(int i=l;i<=r;++i){
        //     for(int j=1;j<i;++j){
        //         if(i%j==0){
        //             cnt++;
        //         }
        //     }
        //     if(cnt==2){
        //         gd++;
        //     }
        // }
        // return gd;
        //funda is-- a number ha two divs if its a square of a prime number!!
        int ul=sqrt(r)+1;
        vector<bool>isP(ul,true);
        isP[0]=isP[1]=false;
        for(int i=2;i*i<=ul;++i){
            if(isP[i]){
                for(int j=i*i;j<ul;j+=i){
                    isP[j]=false;;
                }
            }
        }
        vector<int>sn;
        for(int i=2;i<ul;i++){
            if(isP[i]){
                int sq=i*i;
                if(sq>=l && sq<=r){
                    //within range
                    sn.push_back(sq);
                }
            }
        }
        int  sc=sn.size();
        int tc=r-l+1;
        return tc-sc;
    }
};