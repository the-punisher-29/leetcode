class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> count;
        for(int num:nums){
            count[num]++;
        }
        for(auto it=count.begin();it!=count.end();++it){
            int num=it->first;
            int nc=it->second;
            if(nc>0){
                for(int i=0;i<k;++i){
                    if(count[num+i]<nc){
                        return false;
                    }
                    count[num+i]-=nc;
                }
            }
        }
        return true;
    }
};