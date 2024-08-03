class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int m=target.size();
        int n=arr.size();
        if(m!=n) return false;//bc
        vector<int> freq(1001,0);
        for(int i=0;i<m;++i){
            freq[target[i]]++;
            freq[arr[i]]--;
        }
        for(int count:freq){
            if(count!=0){
                return false;
            }
        }
        return true;
    }
};