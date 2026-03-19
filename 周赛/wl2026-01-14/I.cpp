#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), v(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<vector<int>> g(n + 1);
    for (int i = 2;i <= n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int Ans = 0;
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        if (a[u]) v[u] = a[u] + v[pu];
        else v[u] = 0;
        if (v[u] > m) return;
        if (u != 1 && g[u].size() == 1) Ans ++;
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 1, 0);
    cout << Ans << '\n';
}