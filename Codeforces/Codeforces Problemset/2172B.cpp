#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;

#define LOG 70

struct SegTree
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        LL l, r; 
        double Mi, laz;
        node() { Mi = inf, laz = -1; }
    };
    vector<node> f; vector<double> a;
    SegTree (int _n) { f.resize(_n + 1 << 2 | 3), a.resize(_n + 1 << 1 | 1, inf); }
    void pushup(int p) {
        f[p].Mi = min(f[lc].Mi, f[rc].Mi);
    }
    void pushdown(int p) {
        if (f[p].laz == -1) return;
        if (f[lc].laz == -1) f[lc].laz = f[p].laz;
        else f[lc].laz = min(f[lc].laz, f[p].laz);
        if (f[rc].laz == -1) f[rc].laz = f[p].laz;
        else f[rc].laz = min(f[rc].laz, f[p].laz);
        f[lc].Mi = min(f[lc].Mi, f[p].laz);
        f[rc].Mi = min(f[rc].Mi, f[p].laz);
        f[p].laz = -1;
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].Mi = a[l];
            return;
        }
        LL mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }
    void upd(int p, int l, int r, double v) {
        if (l > r) return;
        if (l <= f[p].l && f[p].r <= r) {
            f[p].Mi = min(f[p].Mi, v);
            if (f[p].laz == -1) f[p].laz = v;
            else f[p].laz = min(f[p].laz, v);
            return;
        }
        pushdown(p);
        LL mid = (f[p].l + f[p].r) >> 1;
        if (l <= mid) upd(lc, l, r, v);
        if (r  > mid) upd(rc, l, r, v);
        pushup(p);
    } 
    double qry(int p, int idx) {
        if (f[p].l == f[p].r) return f[p].Mi;
        pushdown(p);
        LL mid = (f[p].l + f[p].r) >> 1;
        double Mi = inf;
        if (idx <= mid) Mi = min(Mi, qry(lc, idx));
        else            Mi = min(Mi, qry(rc, idx));
        return Mi; 
    }
};

void solve() {
    LL n, m, len, x, y;
    cin >> n >> m >> len >> x >> y;
    vector<pair<LL, LL>> p(n), v(m + 1);
    vector<LL> a(m + 1, 0);
    for (int i = 0;i < n;i ++) cin >> p[i].x >> p[i].y;
    for (int i = 1;i <= m;i ++) cin >> v[i].x, v[i].y = i;
    SegTree f(m + 1);
    f.build(1, 1, m + 1);
    sort(v.begin() + 1, v.end());
    for (int i = 1;i <= m;i ++) a[i] = v[i].x;
    a.push_back(inf);
    for (int i = 0;i < n;i ++) {
        LL l = p[i].x, r = p[i].y;
        double val = 1.0 * (r - l) / x + 1.0 * (len - r) / y;
        // cout << l << ' ' << r << " : ";
        l = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        r = upper_bound(a.begin() + 1, a.end(), r) - a.begin() - 1;
        // cout << l << ' ' << r << ' ' << val << '\n';
        f.upd(1, l, r, val);
    }
    vector<double> ans(m + 1, 0);
    for (int i = 1;i <= m;i ++) {
        ans[v[i].y] = min(1.0 * (len - a[i]) / y, f.qry(1, i));
    }
    for (int i = 1;i <= m;i ++) cout << ans[i] << '\n';
}

int main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}