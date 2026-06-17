#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1);
        vector<int> d(n + 1, 0);
        map<pair<int, int>, int> mp1, mp2;
        for (int i = 1;i <= n;i ++) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back(v);
            g[v].push_back(u);
            mp1[{u, v}] = w;
            mp2[{v, u}] = w;
        }
        int ans1 = 0, ans2 = 0;
        auto dfs1 = [&](auto dfs1, int pu, int u, int s) -> void {
            for (auto v : g[u]) {
                if (v == pu) continue;
                // cout << u << ' ' << v << '\n';
                if (!mp1.count({u, v})) ans1 += mp1[{v, u}];
                if (v == s) continue;
                dfs1(dfs1, u, v, s);
            }
        };
        auto dfs2 = [&](auto dfs2, int pu, int u, int s) -> void {
            for (auto v : g[u]) {
                if (v == pu) continue;
                // cout << u << ' ' << v << '\n';
                if (!mp1.count({u, v})) ans2 += mp1[{v, u}];
                if (v == s) continue;
                dfs2(dfs2, u, v, s);
            }
        };
        // cout << 1 << ' ' << g[1][0] << ":\n";
        if (!mp1.count({1, g[1][0]})) ans1 += mp1[{g[1][0], 1}];
        dfs1(dfs1, 1, g[1][0], 1);
        // cout << 1 << ' ' << g[1][1] << ":\n";
        if (!mp1.count({1, g[1][1]})) ans2 += mp1[{g[1][1], 1}];
        dfs2(dfs2, 1, g[1][1], 1);
        // cout << ans1 << ' ' << ans2 << '\n';
        // cout << ans1 << '\n';
        // dfs1(dfs1, 0, 1, 1, 1);
        cout << min(ans1, ans2) << '\n';
    }   
}