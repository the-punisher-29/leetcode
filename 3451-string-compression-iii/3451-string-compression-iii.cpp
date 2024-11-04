class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int n=word.size();
        int i=0;
        while(i<n){
            char curr_c=word[i];
            int cnt=0;
            while(i<n && word[i]==curr_c && cnt<9){
                cnt++;
                i++;
            }
            comp+=to_string(cnt)+curr_c;
        }
        return comp;
    }
};