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
        auto dfs = [&](auto dfs, int pu, int u, int s, int f) -> void {
            if (u == s) {
                if (!(f ? mp1.count({u, g[u][f]}) : mp2.count({u, g[u][f]}))) (f ? ans1 : ans2) += (f ? mp1[{g[u][f], u}] : mp2[{g[u][f], u}]);
                dfs(dfs, u, g[u][f], s, f);
            }
            for (auto v : g[u]) {
                if (v == pu) continue;
                if (!(f ? mp1.count({u, v}) : mp2.count({u, v}))) (f ? ans1 : ans2) += (f ? mp1[{v, u}] : mp2[{v, u}]);
                if (v == s) return;
                dfs(dfs, u, v, s, f);
            }
        };
        dfs(dfs, 0, 1, 1, 0);
        dfs(dfs, 0, 1, 1, 1);
        cout << min(ans1, ans2) << '\n';
    }   
}