#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

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
    for (int i = 1;i <= n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<LL>> dp(n + 1, vector<LL> (2, 0));
    vector<int> dep(n + 1, 0), fa(n + 1, 0);
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        fa[u] = pu;
        dep[u] = dep[pu] + 1;
        if (siz(g[u]) == 1) {
            if (s[u] == '1') {
                dp[u][1] = 0;
                dp[u][0] = inf;
            } else {
                dp[u][1] = 1;
                dp[u][0] = 0;
            }
        }
        int cnt = 0;
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u);
            
        }
        if (cnt > 1) dp[u][0] = inf;
    };

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
