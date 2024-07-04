class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

    // Create two arrays to store the count of trusts
    // 'trusts_given' will store the number of trusts given by each person
    // 'trusts_received' will store the number of trusts received by each person
    vector<int> trusts_given(n + 1, 0);
    vector<int> trusts_received(n + 1, 0);
    
    // Iterate through the trust array to count trusts
    for (const auto& pair : trust) {
        int a = pair[0];
        int b = pair[1];
        trusts_given[a]++;
        trusts_received[b]++;
    }
    
    // Check for the person who is trusted by everyone except for themselves
    // and who trusts nobody
    for (int i = 1; i <= n; i++) {
        if (trusts_received[i] == n - 1 && trusts_given[i] == 0) {
            return i;
        }
    }
    
    // If no such person is found, return -1
    return -1;
        
        
    }
};