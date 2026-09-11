#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;

using LL = long long;

const LL inf = 1e15;

struct SegTree
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        LL l, r, val, laz;
    };
    vector<LL> a; vector<node> f;
    SegTree(int _n) {
        a.resize(_n + 1);
        f.resize(_n << 2 | 3);
    }
    void pushup(int p) {
        f[p].val = min(f[lc].val, f[rc].val);
    }
    void pushdown(int p) {
        if (f[p].laz) {
            f[lc].val += f[p].laz * (f[lc].r - f[lc].l + 1);
            f[rc].val += f[p].laz * (f[rc].r - f[rc].l + 1);
            f[lc].laz + f[p].laz;
            f[rc].laz + f[p].laz;
            f[p].laz = 0;
        }
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].val = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }
    void upd(int p, int l, int r, int v) {
        if (r < l) return;
        if (f[p].l >= l && f[p].r <= r) {
            f[p].val += (f[p].r - f[p].l + 1) * v;
            f[p].laz += v;
            return;
        }
        int mid = f[p].l + f[p].r >> 1;
        pushdown(p);
        if (l <= mid) upd(lc, l, r, v);
        if (r >  mid) upd(rc, l, r, v);
        pushup(p);
    }
    LL qry(int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].val;
        int mid = f[p].l + f[p].r >> 1;
        LL mi = inf;
        pushdown(p);
        if (l <= mid) mi = min(mi, qry(lc, l, r));
        if (r >  mid) mi = min(mi, qry(rc, l, r));
        return mi;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<LL> p(n + 1), use(n + 1), alls;
    vector<char> op(n + 1);
    map<LL, LL> val;
    for (int i = 1;i <= n;i ++) {
        cin >> op[i] >> p[i];
        alls.push_back(p[i]);
    }
    sort(all(alls));
    alls.erase(unique(all(alls)), alls.end());
    for (int i = 1;i <= n;i ++) {
        use[i] = lower_bound(all(alls), p[i]) - alls.begin() + 1;
        val[use[i]] = p[i];
    }
    int m = siz(alls);
    SegTree f(m);
    for (int i = 1;i <= m;i ++) f.a[i] = alls[i - 1];
    f.build(1, 1, m);
    // for (int i = 1;i <= m;i ++) cout << f.qry(1, i, i) << '\n';
    for (int i = 1;i <= n;i ++) {
        if (op[i] == '+') {
            f.upd(1, 1, use[i] - 1, 1);
        } else {
            f.upd(1, 1, use[i] - 1, -1);
        }
        for (int i = 1;i <= m;i ++) cout << f.qry(1, i, i) << '\n';
        cout << 1 << ' ' << use[i] - 1 << " : ";
        cout << f.qry(1, 1, m) << '\n';
    }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}