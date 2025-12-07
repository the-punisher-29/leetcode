class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n=s.size();
        int l=0;
        int ans=0;
        for(int r=0;r<n;++r){
            char c=s[r];
            while(st.count(c)){
                st.erase(s[l]);
                l++;
            }
            st.insert(c);
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};