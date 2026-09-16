class Solution {
public:
    static const long long MOD = 1e9 + 7;
    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    int numberOfSets(int n, int k) {
        // We need combinations up to n.
        vector<long long> fact(n + 1), invFact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n; i >= 1; --i)
            invFact[i - 1] = invFact[i] * i % MOD;
        auto C = [&](int N, int R) -> long long {
            if (R < 0 || R > N)
                return 0;
            return fact[N] * invFact[R] % MOD
                         * invFact[N - R] % MOD;
        };
        long long ans = 0;
        for (int s = 0; s <= k - 1; ++s) {
            long long waysToShare = C(k - 1, s);
            long long waysToChoosePoints = C(n, 2 * k - s);
            ans = (ans +
                   waysToShare * waysToChoosePoints) % MOD;
        }
        return ans;
    }
};