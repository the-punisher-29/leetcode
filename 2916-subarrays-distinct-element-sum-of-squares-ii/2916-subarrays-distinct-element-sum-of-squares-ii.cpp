class Solution {
public:
    int n;
    vector<long long> sm, sq, lz;
    void apply(int o, int len, long long d) {
        sq[o] += 2 * d * sm[o] + d * d * len;
        sm[o] += d * len;
        lz[o] += d;
    }
    void push(int o, int l, int r) {
        if (lz[o]) {
            int mid = (l + r) / 2;
            apply(2 * o, mid - l + 1, lz[o]);
            apply(2 * o + 1, r - mid, lz[o]);
            lz[o] = 0;
        }
    }
    void update(int o, int l, int r, int ql, int qr, long long d) {
        if (ql <= l && r <= qr) { apply(o, r - l + 1, d); return; }
        push(o, l, r);
        int mid = (l + r) / 2;
        if (ql <= mid) update(2 * o, l, mid, ql, qr, d);
        if (qr > mid) update(2 * o + 1, mid + 1, r, ql, qr, d);
        sm[o] = sm[2 * o] + sm[2 * o + 1];
        sq[o] = sq[2 * o] + sq[2 * o + 1];
    }
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        n = nums.size();
        sm.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lz.assign(4 * n, 0);
        vector<int> last(100001, -1);
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int p = last[nums[j]];
            update(1, 0, n - 1, p + 1, j, 1);
            last[nums[j]] = j;
            ans = (ans + sq[1] % MOD) % MOD;
        }
        return (int)ans;
    }
};