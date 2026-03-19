#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
using namespace std;
using LL = long long;

struct SegTree {
    struct node {
        LL val, laz, l, r;
        node() {val = laz = l = r = 0;}
    };
    vector<int> a;
    vector<node> f;
    SegTree(int x) {
        a.resize(x + 1, 0);
        f.resize(x << 2 | 1);
    }
    void pushup(int p) {
        f[p].val = min(f[lc].val, f[rc].val);
    }
    void pushdown(int p) {
        if (f[p].laz) {
            f[lc].laz += f[p].laz;
            f[lc].val += f[p].laz;
            f[rc].laz += f[p].laz;
            f[rc].val += f[p].laz;
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
    void upd(int p, int l, int r, int x) {
        if (l <= f[p].l && f[p].r <= r) {
            f[p].val += x;
            f[p].laz += x;
            return;
        }
        pushdown(p);
        int mid = f[p].l + f[p].r >> 1;
        if (l <= mid) upd(lc, l, r, x);
        if (r  > mid) upd(rc, l, r, x);
        pushup(p);
    }
    int qry(int p, int l, int r) {
        if (l == r) return l;
        pushdown(p);
        int mid = l + r >> 1;
        if (f[lc].val < 0) return qry(lc, l, mid);
        else if (f[rc].val < 0) return qry(rc, mid + 1, r);
        else return 0;
    }
};

void solve() {
    int x, y;
    cin >> x >> y;
    int n, m;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    vector<int> p(n + 2, 0), cnt(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        cnt[i] = max(0, a[i] - x) + max(0, b[i] - y);
        if (cnt[i] <= n + 1) p[cnt[i]] += 1;
    }
    SegTree f(n + 2);
    // for (int i = 1;i <= 10;i ++) cout << p[i] << ' ';
    // cout << '\n';
    for (int i = 1;i <= n + 1;i ++) p[i] += p[i - 1];
    // for (int i = 1;i <= 10;i ++) cout << p[i] << ' ';
    // cout << '\n';
    for (int i = n + 1;i >= 1;i --) p[i] = p[i - 1] - i;
    // for (int i = 1;i <= 10;i ++) cout << p[i] << ' ';
    // cout << '\n';
    for (int i = 0;i <= n + 1;i ++) f.a[i] = p[i];
    f.build(1, 1, n + 1);
    cin >> m;
    while (m --) {
        int p, u, v;
        cin >> p >> u >> v;
        int p1 = max(0, a[p] - x) + max(0, b[p] - y);
        a[p] = u, b[p] = v;
        int p2 = max(0, a[p] - x) + max(0, b[p] - y);
        if (p1 < p2) {
            f.upd(1, min(p1 + 1, n + 1), min(p2, n + 1), -1);
        } else if (p2 < p1) {
            f.upd(1, min(p2 + 1, n + 1), min(p1, n + 1),  1);
        }
        cout << f.qry(1, 1, n + 1) - 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T --) solve();
}