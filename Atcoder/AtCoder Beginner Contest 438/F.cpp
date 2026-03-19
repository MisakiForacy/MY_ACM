#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

#define LOG 30

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 2;i <= n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<LL> Sz(n + 1, 0), Fa(n + 1, 0);
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        Sz[u] = 1, Fa[u] = pu;
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, u, v);
            Sz[u] += Sz[v];
        }
    };
    dfs(dfs, -1, 0);
    LL L = 0, R = 0;
    LL Sm = 0;
    for (LL x = 1;x <= n;x ++) {
        
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}