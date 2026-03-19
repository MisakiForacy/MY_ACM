#include <bits/stdc++.h>
using namespace std;

using LL = long long;

struct SegTree
{
    struct node
    {
        LL l, r, Mi;
        node(){Mi = inf;}
    };
    vector<node> f; vector<LL> a;
    SegTree(int _n) {f.resize(_n << 2 | 3), a.resize(_n + 1); }
    void pushup(int p) {
        f[p].Mi = min(f[p << 1].Mi, f[p << 1 | 1].Mi);
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].Mi = a[l];
            return;
        }
        int Mid = l + r >> 1;
        build(p << 1, l, Mid);
        build(p << 1 | 1, Mid + 1, r);
        pushup(p);
    }
    void upd(int p, int idx, int v) {
        if (f[p].l == f[p].r) {
            f[p].Mi = v;
            return;
        }
        int Mid = f[p].l + f[p].r >> 1;
        if (idx <= Mid) upd(p << 1, idx, v);
        else        upd(p << 1 | 1, idx, v);
        pushup(p);
    }
    LL qryMi(int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Mi;
        LL Mi = inf, Mid = f[p].l + f[p].r >> 1;
        if (l <= Mid) Mi = min(Mi, qryMi(p << 1, l, r));
        if (r > Mid) Mi = min(Mi, qryMi(p << 1 | 1, l, r));
        return Mi;
    }
};