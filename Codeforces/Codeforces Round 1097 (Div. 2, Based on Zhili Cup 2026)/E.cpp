#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n + 1);
    vector<LL> f(n + 1, 0), l(n + 1, 0), dis(n + 1, 0), fa(n + 1, 0);
    for (int i = 1;i <= n;i ++) g[i].push_back(-1);
    for (int i = 2;i <= n;i ++) cin >> f[i], g[f[i]].push_back(i);
    for (int i = 2;i <= n;i ++) cin >> l[i];
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        fa[u] = pu;
        dis[u] = dis[pu] + l[u];
        for (auto v : g[u]) {
            if (v == -1) continue;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 1, 0);
    vector<LL> fval(n + 1, 0);
    auto dfs1 = [&](auto dfs1, int u, int pu) -> void {
        int sz = siz(g[u]) - 1;
        int cnt = 1;
        for (auto v : g[u]) {
            if (v == -1) continue;
            fval[v] = cnt;
            cnt ++;
            dfs(dfs, v, u);
        }
    };
}

int main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
