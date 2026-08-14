#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

#define x first 

#define y second 

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1), p(n + 1);
    vector<int> fa(n + 1, 0);
    for (int i = 1;i <= n - 1;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    vector<bool> vis(n + 1, 0);
    vector<LL> dis(n + 1, 0);
    vis[1] = 1;
    dis[1] = 0;
    q.push(1);
    map<int, int> mp;
    vector<int> ti(m + 1, 0);
    while (siz(q)) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (vis[v]) continue;
            q.push(v);
            dis[v] = dis[u] + 1;
            vis[v] = 1;
            // cout << v << ' ' << u << ' ' << dis[v] << ' ' << dis[u] << '\n';
        }
    }
    // for (int i = 1;i <= n;i ++) {
    //     cout << dis[i] << ' ';
    // }
    // cout << '\n';
    for (int i = 1;i <= m;i ++) {
        LL x, s;
        cin >> x >> s;
        ti[i] = dis[x] + s;
        if (x != 1)
            mp[ti[i]] ++;
        else    
            ti[i] = -1;
    }
    for (int i = 1;i <= m;i ++) {
        cout << (mp[ti[i]] == 1 || ti[i] == -1);
    }
    cout << '\n';
} 

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
