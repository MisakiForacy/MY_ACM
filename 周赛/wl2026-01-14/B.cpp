#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<PII> p;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        p.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int bad = 0;
    vector<int> C(n + 1, -1), vis(n + 1, 0);
    auto dfs = [&](auto dfs, int u, int f) -> void {
        vis[u] = 1;
        C[u] = f;
        for (auto v : g[u]) {
            if (C[v] == C[u]) bad = 1;
            if (vis[v]) continue;
            dfs(dfs, v, f ^ 1);
        }
    };
    dfs(dfs, 1, 1);
    for (int i = 0;i < m;i ++) if (C[p[i].x] == C[p[i].y]) bad = 1;
    if (bad) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0;i < m;i ++) {
            if (C[p[i].x]) cout << 0;
            else cout << 1;
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}