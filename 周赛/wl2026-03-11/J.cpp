#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

struct SegTree
{
    #define ls p << 1
    #define rs p << 1 | 1
    struct node
    {
        LL l, r, Mx, id;
        node(){Mx = 0;}
    };
    vector<node> f; vector<LL> a;
    SegTree(int _n) {f.resize(_n << 2 | 3), a.resize(_n + 1); }
    void pushup(int p) {
        f[p].Mx = max(f[ls].Mx, f[rs].Mx);
        if (f[ls].Mx > f[rs].Mx) {
            f[p].id = f[ls].id;
        } else {
            f[p].id = f[rs].id;
        }
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].Mx = a[l];
            f[p].id = l;
            return;
        }
        int Mid = l + r >> 1;
        build(ls, l, Mid);
        build(rs, Mid + 1, r);
        pushup(p);
    }
    pair<LL, LL> qryMx(int p, int l, int r) {
        // cout << l << ' ' << r << '\n';
        if (l <= f[p].l && f[p].r <= r) return {f[p].Mx, f[p].id};
        int mid = f[p].l + f[p].r >> 1;
        int idx = f[p].id;
        int mx = 0;
        if (l <= mid) {
            pair<LL, LL> res = qryMx(ls, l, r);
            if (res.x > mx) {
                mx = res.x;
                idx = res.y;
            }
        }
        if (r > mid) {
            pair<LL, LL> res = qryMx(rs, l, r);
            if (res.x > mx) {
                mx = res.x;
                idx = res.y;
            }
        }
        return {mx, idx};
    }
};
map<pair<int, int>, LL> memo;

void solve() {
    int n, q;
    cin >> n >> q;
    SegTree f(n);
    for (int i = 1;i <= n;i ++) cin >> f.a[i];
    f.build(1, 1, n);
    // cout << "ok\n";
    auto dfs = [&](auto dfs, int l, int r) -> LL {
        // cout << l << ' ' << r << '\n';
        if (l > r) return 0;
        if (memo.count({l, r})) return memo[{l, r}];
        int mid = f.qryMx(1, l, r).y;
        LL res = (r - l + 1) + dfs(dfs, l, mid - 1) + dfs(dfs, mid + 1, r);
        memo[{l, r}] = res;
        return res;
    };
    dfs(dfs, 1, n);
    vector<int> L(q + 1, 0), R(q + 1, 0);
    for (int i = 1;i <= q;i ++) cin >> L[i];
    for (int i = 1;i <= q;i ++) cin >> R[i];
    for (int i = 1;i <= q;i ++) {
        cout << dfs(dfs, L[i], R[i]) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}