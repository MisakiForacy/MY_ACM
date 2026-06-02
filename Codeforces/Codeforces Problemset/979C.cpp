#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    LL n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i < n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LL ans = n * (n - 1) / 2;
    vector<LL> sz(n + 1, 1), use(n + 1, 0);
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        if (u == y) use[u] = 1;
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u);
            sz[u] += sz[v];
            use[u] = max(use[u], use[v]);
        }
    };
    dfs(dfs, x, 0);
    for (auto v : g[x]) {
        if (use[v] == 1) {
            ans += (sz[v] - sz[y]) * sz[y];
        }
    }
    n = n - sz[y];
    ans += (sz[y]) * (sz[y] - 1) / 2;
    ans += n * (n - 1) / 2;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}