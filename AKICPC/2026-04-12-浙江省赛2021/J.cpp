#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<LL> v(n + 1, 0);
    for (int i = 2;i <= n;i ++) cin >> v[i];
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<LL> d(n + 1, 0), vis(n + 1, 0), w(n + 1, 0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (siz(q)) {
        auto u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!vis[v]) {
                d[v] = d[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i = 1;i <= n;i ++) w[i] = d[i] * 2;
    vector<LL> dp(t + 1, 0);
    for (int i = 1;i <= n;i ++) {
        for (int j = w[i];j <= t;j ++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    for (int i = 1;i <= t;i ++) cout << dp[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}