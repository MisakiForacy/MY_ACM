#include <bits/stdc++.h>

#define lowbit(x) (x & (-x))

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), fa(n + 1, 0), alls;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i], alls.push_back(a[i]);
    for (int i = 2;i <= n;i ++) 
        cin >> fa[i], g[fa[i]].push_back(i);
    vector<int> f(n + 1, 0), ans(n + 1, 0);
    
    sort(all(alls));

    for (int i = 1;i <= n;i ++)
        a[i] = lower_bound(all(alls), a[i]) - alls.begin() + 1;

    auto add = [&](int x, int val) -> void {
        for (;x <= n;x += lowbit(x)) f[x] += val;
    };

    auto qry = [&](int x) -> int {
        int sum = 0;
        for (;x;x -= lowbit(x)) sum += f[x];
        return sum;
    };

    vector<int> sz(n + 1, 0), mx(n + 1, -1), son(n + 1, -1);

    auto dfs1 = [&](auto dfs1, int u) -> void {
        sz[u] = 1;
        for (int v : g[u]) {
            sz[u] += sz[v];
        }
    };

    auto modify = [&](auto modify, int u, int val) -> void {
        add(a[u], val);
        for (int v : g[u]) {
            if (son[v] == -1)
                modify(modify, v, val);
        }
    };
    
    auto dfs2 = [&](auto dfs2, int u, int s) -> void {
        for (int v : g[u]) {
            if (v == son[u]) 
                dfs2(dfs2, v, s);
        }
        modify(modify, u, 1);
        ans[u] = qry(n) - qry(a[u]);
        
        if (!s) modify(modify, u, -1);
    };

    for (int u = 1;u <= n;u ++) {
        modify(modify, u, 1);
        ans[u] = qry(n) - qry(a[u]);
        modify(modify, u, -1);
    }
    for (int i = 1;i <= n;i ++) cout << ans[i] << '\n';
}

int main() {
    // freopen("query.in", "r", stdin);
    // freopen("query.out", "w", stdout);
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}

