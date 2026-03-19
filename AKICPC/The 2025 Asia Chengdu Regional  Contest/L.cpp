#include <bits/stdc++.h>
using namespace std;
using LL = long long;

#define LOG 40

const LL inf = 2e9;

struct DynamicSegmentTree
{
    LL n, ncnt = 0, rt = 0;
    vector<LL> rc, lc, V, A, B, Sum;
    DynamicSegmentTree (int _n = 0) 
    {
        this->n = _n + 1;
        lc.resize(n * LOG, 0);
        rc.resize(n * LOG, 0);
        A.resize(n * LOG, 0);
        B.resize(n * LOG, 0);
    }
    void pushup (int p) {
        A[p] = A[lc[p]] + A[rc[p]];
        B[p] = B[lc[p]] + B[rc[p]];
    }
    // void upd (LL &p, int l, int r, int x, int val) {
    //     if (!p) { p = ++ ncnt;}
    //     if (l == r) {
    //         Min[p] = val;
    //         Max[p] = val;
    //         return;
    //     }
    //     int mid = l + r >> 1;
    //     if (x <= mid) upd (lc[p], l, mid, x, val);
    //     else          upd (rc[p], mid + 1, r, x, val);
    //     pushup (p);
    // }
    void merge (int a, int b, int l, int r) {
        if (!a) return b;
        if (!b) return a;
        if (l == r) {
            A
            return a;
        }
        int mid = l + r >> 1;
        lc[a] = merge(lc[a], lc[b], l, mid);
        rc[a] = merge(rc[a], rc[b], mid + 1, r);
        pushup(a);
        return a;
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

void solve () {
    
}

/*
2
5 3 2 1
-3 0 3
2 -2 -1
1 1 1
0 0 0
-1 -1 -1
3 2 -1 1
-1 -2 
-3 -3
1 -3
*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}