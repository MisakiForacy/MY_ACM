#include <bits/stdc++.h>

using namespace std;
using LL = long long;

struct SegTree
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        LL l, r, mx;
    };
    vector<int> a;
    vector<node> f;
    SegTree (int _n) {
        a.resize(_n + 1);
        f.resize(_n << 2 | 3);
    }
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
    void upd(int p, int id, int val) {
        if (f[p].l == f[p].r) {
            f[p].mx = val;
            return;
        }
        int mid = f[p].l + f[p].r >> 1;
        if (id <= mid)
            upd(lc, id, val);
        else 
            upd(rc, id, val);
        pushup(p);
    }
    int qry(int p, int l, int r) {
        if (l > r) return -1;
        if (l <= f[p].l && f[p].r <= r) return f[p].mx;
        int mid = f[p].l + f[p].r >> 1;
        int mx = 0;
        if (l <= mid) 
            mx = max(mx, qry(lc, l, r));
        if (r >  mid)
            mx = max(mx, qry(rc, l, r));
        return mx;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> dp(2 * n + 1, 0), mx(n + 1, 0), ok(n + 1, 1);
    for (int i = 1;i <= n;i ++) cin >> a[i], dp[i + n] = -1;
    dp[n + 1] = 0;
    SegTree f(n);
    f.build(1, 1, n);
    auto dfs = [&](auto dfs, int u, int v) -> void {
        for (;u <= n;u += a[u] + 1) {
            v = u + a[u] + 1;
            if (v > n) {
                if (v == n + 1) {
                    dp[u] = 1;
                    mx[u] = 1;
                    f.upd(1, u, dp[u]);
                    // mx[u] = max(mx[u], f.qry(1, u + 1, n) + 1);
                    int nmx = f.qry(1, u + 1, n) + 1;
                    if (nmx > mx[u]) {
                        mx[u] = nmx;
                        ok[u] = 0;
                    }
                } else {
                    dp[u] = -1;
                    mx[u] = 0;
                    f.upd(1, u, dp[u]);
                    int nmx = f.qry(1, u + 1, n) + 1;
                    if (nmx > mx[u]) {
                        mx[u] = nmx;
                        ok[u] = 0;
                    }
                }
                return;
            } else if (dp[v]) {
                if (~dp[v]) {
                    dp[u] = dp[v] + 1;
                    mx[u] = mx[v] + 1;
                    f.upd(1, u, dp[u]);
                    int nmx = f.qry(1, u + 1, v) + 1;
                    if (nmx > mx[u]) {
                        mx[u] = nmx;             
                        ok[u] = 0;
                    }
                } else {
                    dp[u] = dp[v];
                    mx[u] = mx[v] + 1;
                    f.upd(1, u, dp[u]);
                    int nmx = f.qry(1, u + 1, v) + 1;
                    if (nmx > mx[u]) {
                        mx[u] = nmx;
                        ok[u] = 0;
                    }
                }
                return;
            }
            dfs(dfs, u, v);
        }
    };  
    for (int i = n - 1;i >= 0;i --) {
        // cout << "ok : " << i << '\n';
        dfs(dfs, i + 1, i + 1);
    }
    // for (int i = 1;i <= n;i ++) 
    //     cout << dp[i] << " \n"[i == n];
    // for (int i = 1;i <= n;i ++) 
    //     cout << mx[i] << " \n"[i == n];
    for (int i = 1;i <= n - 1;i ++) {
        if (a[i] == dp[i + 1]) {
            cout << 0 << ' ';
        } else if (a[i] <= mx[i + 1] + ok[i + 1] || dp[i + 1] != -1) {
            cout << 1 << ' ';
        } else {
            cout << 2 << ' ';
        }
    }
    cout << '\n';
    // for (int i = 1;i <= n;i ++) 
    //     cout << dp[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}