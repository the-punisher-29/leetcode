class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> fMap;
        int maxf=0;
        int count=0;
        for(int num:nums){
            maxf=max(maxf,++fMap[num]);
        }
        for(auto &pair:fMap){
            if(pair.second==maxf){
                count+=pair.second;
            }
        }
        return count;
    }
};