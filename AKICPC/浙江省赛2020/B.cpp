#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

struct SegTree
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        LL l, r, mx;
        node() { mx = 0; }
    };
    vector<LL> a; vector<node> f;
    SegTree(int _n) { a.resize(_n + 1), f.resize(_n << 2 | 3); }
    void pushup(int p) {
        f[p].mx = max(f[lc].mx, f[rc].mx);
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].mx = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }
    int qry(int p, int k) {
        if (f[p].mx < k) return -1;
        if (f[p].l == f[p].r) return f[p].l;
        int mid = f[p].l + f[p].r >> 1;
        if (f[lc].mx >= k) {
            return qry(lc, k);
        } else {
            return qry(rc, k);
        }
    }
    void upd(int p, int idx, int k) {
        if (f[p].l == f[p].r) {
            f[p].mx += k;
            return;
        }
        int mid = f[p].l + f[p].r >> 1;
        if (idx <= mid) {
            upd(lc, idx, k);
        } else {
            upd(rc, idx, k);
        }
        pushup(p);
    }
};


void solve() {
    int n, C;
    cin >> n >> C;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    SegTree f(n + 1);
    f.build(1, 1, n);
    auto cal1 = [&]() -> LL {
        int r = 1;
        for (int i = 1;i <= n;i ++) {
            if (f.f[1].mx < a[i]) f.upd(1, r ++, C);
            int idx = f.qry(1, a[i]);
            f.upd(1, idx, -a[i]);
            // cout << r << '\n';
        }
        return r - 1;
    };
    auto cal2 = [&]() -> LL {
        multiset<LL> p;
        for (int i = 1;i <= n;i ++) {
            if (p.empty() || a[i] > *p.rbegin()) p.insert(C);
            auto it = p.lower_bound(a[i]);
            LL k = *it - a[i];
            p.erase(it);
            p.insert(k);
        }
        return siz(p);
    };
    cout << cal1() << ' ' << cal2() << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}