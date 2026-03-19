#include <bits/stdc++.h>

#define LOG 40

using namespace std;
using LL = long long;

const LL inf = 2e9;

struct DynamicSegmentTree
{
    LL n, ncnt = 0, rt = 0;
    vector<LL> rc, lc, Max, Min;
    DynamicSegmentTree (int _n = 0) 
    {
        this->n = _n + 1;
        lc.resize(n * LOG, 0);
        rc.resize(n * LOG, 0);
        Min.resize(n * LOG, inf);
        Max.resize(n * LOG, 0);
    }
    void pushup (int p) {
        Max[p] = max(Max[lc[p]], Max[rc[p]]);
        Min[p] = min(Min[lc[p]], Min[rc[p]]);
    }
    void upd (LL &p, int l, int r, int x, int val) {
        if (!p) { p = ++ ncnt;}
        if (l == r) {
            Min[p] = val;
            Max[p] = val;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid) upd (lc[p], l, mid, x, val);
        else          upd (rc[p], mid + 1, r, x, val);
        pushup (p);
    }
    LL askMax (int p, int l, int r, int L, int R) {
        if (L > R) return -1;
        if (!p) return 0;
        if (L <= l && r <= R) return Max[p];
        LL Max = 0;
        int mid = l + r >> 1;
        if (L <= mid) Max = max(Max, askMax (lc[p], l, mid, L, R));
        if (R >  mid) Max = max(Max, askMax (rc[p], mid + 1, r, L, R));
        return Max;
    }
};
