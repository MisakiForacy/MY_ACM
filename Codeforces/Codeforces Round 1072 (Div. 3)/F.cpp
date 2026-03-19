#include <bits/stdc++.h>

#define x first
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1), dp(n + 1, vector<int> (3, 0));
    vector<int> Fa(n + 1, 0);
    for (int i = 2;i <= n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        Fa[u] = pu;
        int Tp = 0;
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u);
            if (Tp) {
                vector<int> ndp(3);
                for (int i = 0;i < 3;i ++) if (dp[u][i]) {
                    for (int j = 0;j < 3;j ++) if (dp[v][j]) {
                        ndp[(i + j) % 3] = 1;
                    }
                }
                dp[u] = ndp;
            } else {
                dp[u] = dp[v];
            }
            Tp ++;
        }
        dp[u][1] = 1;
    };
    dfs(dfs, 1, 0);
    cout << (dp[1][0] ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}