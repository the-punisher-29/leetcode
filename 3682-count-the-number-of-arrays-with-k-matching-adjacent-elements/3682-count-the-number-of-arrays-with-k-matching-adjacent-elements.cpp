// class Solution {
// public:
//     int countGoodArrays(int n, int m, int k) {
//         const int MOD = 1e9 + 7;
//         // dp[i][j] = number of ways to fill first i positions with exactly j equal pairs
//         vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
//         //first position can be any of m values, with 0 equal pairs
//         dp[1][0] = m;
//         for (int i = 2; i <= n; i++) {
//             for (int j = 0; j <= min(k, i - 1); j++) {
//                 // Case 1: arr[i] != arr[i-1] (no new equal pair)
//                 // We can choose any of (m-1) values different from arr[i-1]
//                 if (j <= i - 2) {
//                     dp[i][j] = (dp[i][j] + dp[i-1][j] * (m - 1)) % MOD;
//                 }
//                 // Case 2: arr[i] == arr[i-1] (creates 1 new equal pair)
//                 // We must choose the same value as arr[i-1]
//                 if (j > 0) {
//                     dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
//                 }
//             }
//         }
//         return dp[n][k];
//     }
// };
class Solution {
    using ll = long long;
    int MOD = 1e9+7;
    vector<int> fact,inv_fact;
    int binaryExp(ll a,ll b){
        ll res = 1;
        while(b){
            if(b&1)
                res = (res*a)%MOD;
            a = (a*a)%MOD;
            b /= 2;
        }
        return res;
    }
    int MMI(int val){
        return binaryExp(val,MOD-2);
    }
    void inverseFact(const int& n){
        inv_fact = vector<int>(n+1);
        inv_fact[n] = MMI(fact[n]);
        for(int i=n;i>0;--i)
            inv_fact[i-1] = (1LL*inv_fact[i]*i)%MOD;
    }
    void factorial(const int& n){
        fact = vector<int>(n+1);
        fact[0] = 1;
        for(int i=1;i<=n;++i)
            fact[i] = (1LL*i*fact[i-1])%MOD;
    }
    void precompute(const int& n){
        factorial(n);
        inverseFact(n);
    }
public:
    int countGoodArrays(int n, int m, int k) {
        precompute(n);
        int run_ways = ((1LL * fact[n-1] * inv_fact[n-k-1])%MOD * inv_fact[k])%MOD;
        int ways_to_assign = (1LL * m * binaryExp(m-1,n-k-1))%MOD;
        return (1LL * run_ways * ways_to_assign)%MOD;
    }
};