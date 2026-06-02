#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e15;

struct node
{
    LL v, w;
    bool operator < (const node&T) const {
        return w < T.w;
    }
};

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], a[i] %= k;
    vector<vector<node>> g(n + 1);
    map<pair<int, int>, LL> cont;
    for (int i = 1;i <= m;i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    LL ans = inf;
    vector<int> vis(n + 1, 0);
    auto dfs = [&](auto dfs, int u, int c, LL s, LL w) -> void {
        if (s % k == 0) ans = min(ans, w);
        if (c == 0) return;
        for (auto [v, ww] : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dfs(dfs, v, c - 1, s + a[v], w + ww);
                vis[v] = 0;
            }
        }
    };
    for (int i = 1;i <= n;i ++) {
        vis[i] = 1;
        dfs(dfs, i, k - 1, a[i], 0);
        vis[i] = 0;
    }
    if (ans == inf) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}