#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> p(n + 1), vis(n + 1, 0), pth(n + 1, 0), d(n + 1, 0), f(n + 1);
    vector<vector<int>> g(n + 1), G(n + 1);
    for (int i = 1;i <= n;i ++) cin >> p[i];
    for (int i = 1;i <= n;i ++) f[i] = i;
    for (int i = 1;i <= n;i ++) g[i].push_back(p[i]), G[p[i]].push_back(i), d[p[i]] ++;
    vector<vector<int>> val(n + 1, vector<int> (2, 0));
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (2, 0)));
    for (int i = 1;i <= n;i ++) val[i][1] = 1;
    auto find = [&](auto find, int x) -> int {
        return (f[x] == x ? f[x] : f[x] = find(find, f[x]));
    };
    auto merge = [&](int u, int v) -> void {
        u = find(find, u), v = find(find, v);
        if (u == v) return;
        if (u > v) swap(u, v);
        f[u] = v;
    };
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        for (auto v : G[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u);
            val[u][0] += max(val[v][1], val[v][0]);
            val[u][1] += val[v][0];
        }
    };
    for (int i = 1;i <= n;i ++) {
        if (find(find, i) == find(find, p[i])) {
            int u = i, v = p[u];
            if (d[v] > 1) dfs(dfs, v, u);
            dp[v][0][0] = val[v][0];
            dp[v][1][1] = val[v][1];
            u = v, v = p[u];
            while (v != p[i]) {
                if (d[v] > 1) dfs(dfs, v, u);
                if (p[v] != p[i]) {
                    dp[v][0][0] = max(dp[u][0][0], dp[u][0][1]) + val[v][0];
                    dp[v][0][1] = dp[u][0][0] + val[v][1];
                    dp[v][1][0] = max(dp[u][1][0], dp[u][1][1]) + val[v][0];
                    dp[v][1][1] = dp[u][1][0] + val[v][1];
                } else {
                    dp[v][0][0] = max(dp[u][0][0], dp[u][0][1]) + val[v][0];
                    dp[v][0][1] = dp[u][0][0] + val[v][1];
                    dp[v][1][0] = max(dp[u][1][0], dp[u][1][1]) + val[v][0];
                }
                u = v, v = p[u];
            }
            if (i == p[i]) {
                ans += val[i][0];
            } else {
                ans += max({dp[u][0][0], dp[u][0][1], dp[u][1][0], dp[u][1][1]});
            }
        }
        merge(i, p[i]);
    }
    cout << ans << '\n';
    return 0;
}