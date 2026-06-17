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
        queue<int> q;
        q.push();
        while (q.size()) {
            int u = q.front();
            q.pop();

        }
        dfs1(dfs1, 0, 1, 1);
        cout << ans1 << '\n';
        // dfs1(dfs1, 0, 1, 1, 1);
        cout << min(ans1, ans2) << '\n';
    }   
}