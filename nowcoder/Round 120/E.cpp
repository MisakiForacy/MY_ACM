#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve () {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i < n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<LL> dep(n + 1, 0), fa(n + 1, 0), dp(n + 1, 0), Mx(n + 1, 0);
    dep[0] = -1;
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        fa[u] = pu;
        dep[u] = dep[pu] + 1;
        Mx[u] = max(Mx[u], dep[u]);
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs (dfs, v, u);
            Mx[u] = max(Mx[u], Mx[v]);
        }
    };
    auto dfs1 = [&](auto dfs1, int u, int pu) -> void {
        if (Mx[u] == dep[u]) {
            dp[u] = 1;
        }
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs1 (dfs1, v, u);
            if (Mx[u] == Mx[v]) {
                dp[u] += dp[v];
            }
        }
    };
    dfs (dfs, 1, 0);
    for (int i = 1;i <= n;i ++) Mx[i] -= 1;
    dfs1(dfs1, 1, 0);
    for (int i = 1;i <= n;i ++) cout << dp[i] << " \n"[i == n];
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}