#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), fa(n + 1, -1);
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i < n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        fa[u] = pu;
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 1, 0);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}