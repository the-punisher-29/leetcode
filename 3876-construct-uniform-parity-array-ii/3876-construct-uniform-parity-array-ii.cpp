class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        const int INF = INT_MAX;
        int minOdd = INF, minEven = INF;
        for (int v : nums1) {
            if (v % 2 == 0) minEven = min(minEven, v);
            else            minOdd  = min(minOdd, v);
        }
        // Array is already uniform parity — trivially satisfiable via Option A everywhere.
        if (minOdd == INF || minEven == INF) return true;
        // Mixed parities: T=0 (all even) is always infeasible here, since the
        // smallest odd value has no smaller odd to subtract from it.
        // T=1 (all odd) works iff every even value exceeds the smallest odd value,
        // which holds iff minOdd < minEven.
        return minOdd < minEven;
    }
};