#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const LL inf = 1e15;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n - 1;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dep(n + 1, 0);
    vector<vector<LL>> dp(n + 1, vector<LL> (2, inf));
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        dep[u] = dep[pu] + 1;
        if (siz(g[u]) == 1) {
            if (s[u] == '1') {
                dp[u][0] = inf;
                dp[u][1] = 0;
            } else {
                dp[u][0] = 0;
                dp[u][1] = 1;
            }
            return;
        }
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, u, v);
            dp[u][1] = 
        }
    };
    dfs(dfs, 0, 1);
    while (q --) {
        int x, y;
        cin >> x >> y;
        if (dep[x] > dep[y]) swap(x, y);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
