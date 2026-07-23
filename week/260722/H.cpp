#include <bits/stdc++.h>

#define x first 
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<vector<int>> g(n + 1);
    for (int i = 1;i < n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    auto dfs = [&](auto dfs, int u, int pu, int cnt, int K) -> void {
        if (K < 0) {
            ans = max(ans, cnt - 1);
            return;
        }
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u, cnt + 1, K - (a[u] == 1));
        }
    };
    dfs(dfs, 1, 0, 0, k);
    cout << ans << '\n';
}

int main() {
    // freopen("move.in", "r", stdin);
    // freopen("move.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}