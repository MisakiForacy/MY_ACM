#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL inf = 1e15;

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

void solve() {
    int n, q;
    cin >> n >> q;
    SegTree f(n);
    for (int i = 1;i <= n;i ++) cin >> f.a[i];
    f.build(1, 1, n);
    while (q --) {
        int idx, x, y;
        cin >> idx >> x >> y;
        if (idx == 1) {
            f.upd(1, x, y);
        } else {
            auto check = [&](int l, int d) -> int {
                int Mi = f.qryMi(1, l, l + d);
                return Mi < d;
            };
            LL cur = 0;
            for (int j = 20;j >= 0;j --) {
                int Tp = cur + (1LL << j);
                if (x + Tp > y || check(x, Tp)) continue;
                cur = Tp;
            }
            cout << (f.qryMi(1, x, x + cur) == cur) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}