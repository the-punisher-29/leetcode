class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> prexo(n+1,0);
        for(int i=0;i<n;++i){
            prexo[i+1]=prexo[i]^arr[i];
        }//prefix xor array
        vector<int>ans;
        for(const auto &q:queries){
            int l=q[0],r=q[1];
            ans.push_back(prexo[r+1]^prexo[l]);//xor of range l to r
        }
        return ans;
    }
};