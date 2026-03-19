#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p;
    vector<LL> dp(n + 1, 0), f(n + 1, 0), Sz(n + 1, 1);
    for (int i = 1;i <= n;i ++) f[i] = i;
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        p.push_back({u, v});
    }
    auto findx = [&](auto findx, int x) -> int {
        if (f[x] != x) {
            f[x] = findx(findx, f[x]);
        }
        return f[x];
    };
    auto merge = [&](int u, int v) -> void {
        u = findx(findx, u);
        v = findx(findx, v);
        if (u == v) return;
        if (u < v) swap(u, v);
        f[u] = v;
        Sz[v] += Sz[u];
        dp[v] += dp[u];
    };
    for (auto [u, v] : p) 
        merge(u, v), dp[findx(findx, u)] ++;
    int ok = 1;
    for (int i = 1;i <= n;i ++) {
        if (findx(findx, i) == i) {
            if (dp[i] != Sz[i] * (Sz[i] - 1) / 2) {
                ok = 0;
            }
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
