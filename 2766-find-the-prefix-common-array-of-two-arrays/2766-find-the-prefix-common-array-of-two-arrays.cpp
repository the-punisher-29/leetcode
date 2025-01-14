class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n);
        vector<int> freqA(n + 1, 0);
        vector<int> freqB(n + 1, 0);
        int common = 0;
        for(int i = 0; i < n; i++) {
            freqA[A[i]]++;
            if(freqA[A[i]] <= freqB[A[i]]) {
                common++;
            }
            freqB[B[i]]++;
            if(freqB[B[i]] <= freqA[B[i]]) {
                common++;
            }
            result[i] = common;
        }
        return result;
    }
};