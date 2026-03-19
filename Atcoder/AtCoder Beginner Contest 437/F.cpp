#include <bits/stdc++.h>

#define x first 
#define y second 

using namespace std;
using LL = long long;

using PII = pair<LL, LL>;

const LL inf = 1e15;

struct SegTree
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        LL l, r, Mi, Mx;
    };
    vector<node> f; vector<LL> a;
    SegTree (int _n) {
        f.resize(_n << 2 | 3);
        a.resize(_n + 1);
    }
    void pushup(int p) {
        f[p].Mi = min(f[lc].Mi, f[rc].Mi);
        f[p].Mx = max(f[lc].Mx, f[rc].Mx);
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].Mi = f[p].Mx = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }
    void upd(int p, int px, LL v) {
        if (f[p].l == f[p].r) {
            f[p].Mi = f[p].Mx = v;
            return;
        }
        int mid = f[p].l + f[p].r >> 1;
        if (px <= mid) upd(lc, px, v);
        else           upd(rc, px, v);
        pushup(p);
    }
    LL qryMx(int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Mx;
        int mid = f[p].l + f[p].r >> 1;
        LL Mx = -inf;
        if (l <= mid) Mx = max(Mx, qryMx(lc, l, r));
        if (r  > mid) Mx = max(Mx, qryMx(rc, l, r));
        return Mx;
    }
    LL qryMi(int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Mi;
        int mid = f[p].l + f[p].r >> 1;
        LL Mi = inf;
        if (l <= mid) Mi = min(Mi, qryMi(lc, l, r));
        if (r  > mid) Mi = min(Mi, qryMi(rc, l, r));
        return Mi;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<LL> x(n + 1), y(n + 1);
    for (int i = 1;i <= n;i ++) {
        cin >> x[i] >> y[i];
    }
    SegTree f1(n), f2(n);
    for (int i = 1;i <= n;i ++) {
        f1.a[i] = x[i] + y[i];
        f2.a[i] = x[i] - y[i];
    }
    f1.build(1, 1, n), f2.build(1, 1, n);
    while (q --) {
        int opt, px, L, R, xx, yy;
        cin >> opt;
        if (opt == 1) {
            cin >> px >> xx >> yy;
            f1.upd(1, px, xx + yy);
            f2.upd(1, px, xx - yy);
        } else {
            cin >> L >> R >> xx >> yy;
            LL Mx = 0;
            Mx = max(Mx, abs((xx + yy) - f1.qryMi(1, L, R)));
            Mx = max(Mx, abs(f1.qryMx(1, L, R) - (xx + yy)));
            Mx = max(Mx, abs((xx - yy) - f2.qryMi(1, L, R)));
            Mx = max(Mx, abs(f2.qryMx(1, L, R) - (xx - yy)));
            cout << Mx << '\n';
        }
    }
}