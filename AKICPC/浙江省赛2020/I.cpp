#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<LL> a(n + 1, 0), b(n + 1, 0), alls;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i] >> b[i];
        alls.push_back(a[i]);
        alls.push_back(b[i]);
    }
    sort(all(alls));
    // cout << '\n';
    alls.erase(unique(all(alls)), alls.end());
    for (int i = 1;i <= n;i ++) {
        a[i] = lower_bound(all(alls), a[i]) - alls.begin() + 1;
        b[i] = lower_bound(all(alls), b[i]) - alls.begin() + 1;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
        // cout << a[i] << ' ' << b[i] << '\n';
    }
    vector<int> vis(n + 1, 0);
    int ans = 0, cnt = 0;
    auto dfs = [&](auto dfs, int u) -> void {
        vis[u] = 1;
        cnt ++;
        for (auto v : g[u]) {
            if (!vis[v]) {
                dfs(dfs, v);
            }
        }
    };
    for (int i = 1;i <= n;i ++) {
        if (!vis[i]) {
            cnt = 0;
            dfs(dfs, i);
            ans = max(ans, cnt);
        }
    }
    cout << ans << '\n';
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}