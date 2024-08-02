class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int noo=count(nums.begin(),nums.end(),1);
        //bc
        if(noo==0 || noo==n) return 0;
        //concatenating for circular prop
        vector<int> ext(nums);
        ext.insert(ext.end(),nums.begin(),nums.end());
        //sliding window
        int zinw=0;//counting no of zeroes in window
        for(int i=0;i<noo;++i){
            if(ext[i]==0) zinw++;
        }
        int min_swaps=zinw;
        for(int i=noo;i<n+noo;++i){
            if(ext[i-noo]==0) zinw--;
            if(ext[i]==0) zinw++;
            min_swaps=min(min_swaps,zinw);//min zeroes is min swap
        }
        return min_swaps;
    }
};