class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> count;//count of each ele
        for(int num:arr1){
            count[num]++;
        }
        vector<int> r;// adding from arr2 to r
        for(int num:arr2){
            while(count[num]>0){
                r.push_back(num);
                count[num]--;
            }
        }
        vector<int> rem;//adding rem ele
        for(auto& entry:count){
            while(entry.second>0){
                rem.push_back(entry.first);
                entry.second--;
            }
        }
        sort(rem.begin(),rem.end());//rem in asce
        r.insert(r.end(),rem.begin(),rem.end());//appended
        return r;
    }
};