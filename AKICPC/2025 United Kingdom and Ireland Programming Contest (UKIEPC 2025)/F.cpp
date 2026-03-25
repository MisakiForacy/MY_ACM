#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> h(n + 1);
    set<LL> use;
    for (int i = 1;i <= n;i ++) cin >> h[i], use.insert(h[i]);
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    LL ans = 1e9;
    auto check = [&](LL Mx, LL Mi) -> int {
        if (!(Mi <= h[1] && h[1] <= Mx)) return 0;
        if (!(Mi <= h[2] && h[2] <= Mx)) return 0;
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        while (siz(q)) {
            auto u = q.front();
            q.pop();
            if (u == 2) return 1;
            for (auto v : g[u]) {
                if (vis[v]) continue;
                if (!(Mi <= h[v] && h[v] <= Mx)) continue;
                q.push(v);
                vis[v] = 1;
            }
        }
        return 0;
    };
    for (int Hi : use) {
        if (h[1] > Hi || h[2] > Hi) continue;
        LL lo = 0, hi = 1e6;
        while (lo < hi) {
            LL mid = lo + hi >> 1;
            if (check(Hi, Hi - mid)) hi = mid;
            else lo = mid + 1;
        }
        // cout << Hi << ' ' << lo << '\n';
        ans = min(ans, lo);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}