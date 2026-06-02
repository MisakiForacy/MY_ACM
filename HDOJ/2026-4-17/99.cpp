#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

int n, m, K;
vector<vector<pair<int,ll>>> g;
vector<int> a;
vector<char> vis;
ll ans;

void dfs(int u, int res, ll dist, int depth) {
    if (res % K == 0) ans = min(ans, dist);
    if (depth == K) return;
    for (auto &e : g[u]) {
        int v = e.first; ll w = e.second;
        if (!vis[v]) {
            if (dist + w >= ans) continue;
            vis[v] = 1;
            dfs(v, (res + a[v]) % K, dist + w, depth + 1);
            vis[v] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        cin >> n >> m >> K;
        a.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] %= K;
            if (a[i] < 0) a[i] += K;
        }
        g.assign(n + 1, {});
        for (int i = 0; i < m; ++i) {
            int x, y; ll w;
            cin >> x >> y >> w;
            g[x].push_back({y, w});
            g[y].push_back({x, w});
        }
        vis.assign(n + 1, 0);
        ans = INF;
        for (int s = 1; s <= n; ++s) {
            if (a[s] % K == 0) ans = 0;
            vis[s] = 1;
            dfs(s, a[s] % K, 0LL, 1);
            vis[s] = 0;
        }
        if (ans == INF) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}