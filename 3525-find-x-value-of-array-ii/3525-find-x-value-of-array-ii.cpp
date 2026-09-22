class Solution {
public:
    int n, K;
    vector<array<array<int,5>,5>> mat;
    vector<int> prodv;
    vector<int> a;

    void merge(int node) {
        int left = 2*node, right = 2*node+1;
        prodv[node] = (prodv[left] * prodv[right]) % K;
        for (int v = 0; v < K; v++) {
            int mv = (v * prodv[left]) % K;
            for (int x = 0; x < K; x++)
                mat[node][v][x] = mat[left][v][x] + mat[right][mv][x];
        }
    }

    void setLeaf(int node, int val) {
        for (int v = 0; v < K; v++)
            for (int x = 0; x < K; x++)
                mat[node][v][x] = ((v * val) % K == x) ? 1 : 0;
        prodv[node] = val;
    }

    void build(int node, int l, int r) {
        if (l == r) { setLeaf(node, a[l]); return; }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        merge(node);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { a[l] = val; setLeaf(node, val); return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        merge(node);
    }

    void query(int node, int l, int r, int start, int x, int &v, int &ans) {
        if (r < start) return;
        if (l >= start) {
            ans += mat[node][v][x];
            v = (v * prodv[node]) % K;
            return;
        }
        int mid = (l + r) / 2;
        query(2*node, l, mid, start, x, v, ans);
        query(2*node+1, mid+1, r, start, x, v, ans);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size(); K = k;
        a.resize(n);
        for (int i = 0; i < n; i++) a[i] = nums[i] % K;

        mat.assign(4*n, {});
        prodv.assign(4*n, 0);
        build(1, 0, n-1);

        vector<int> result;
        result.reserve(queries.size());
        for (auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            update(1, 0, n-1, idx, val % K);
            int v = 1 % K, ans = 0;
            query(1, 0, n-1, start, x, v, ans);
            result.push_back(ans);
        }
        return result;
    }
};