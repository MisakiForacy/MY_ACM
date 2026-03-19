#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 60

using namespace std;
using LL = long long;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n - 1;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<map<LL, int>> use(n + 1);
    vector<int> ans(n + 1, -1);
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        if (use[u].count(a[u])) ans[u] = 1;
        else ans[u] = 0;
        use[u][a[u]] = 1;
        for (auto v : g[u]) {
            if (v == pu) continue;
            use[v] = use[u];
        }
        use[u].clear();
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 1, 0);
    for (int i = 1;i <= n;i ++) {
        cout << (ans[i] ? "Yes\n" : "No\n");
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}