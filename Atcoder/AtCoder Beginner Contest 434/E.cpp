#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve () {
    int n;
    cin >> n;
    vector<pair<LL, LL>> edge;
    vector<LL> p;
    for (int i = 0;i < n;i ++) {
        LL X, R;
        cin >> X >> R;
        edge.push_back({X - R, X + R});
        p.push_back(X - R);
        p.push_back(X + R);
    }
    sort(all(p));
    p.erase(unique(all(p)), p.end());
    int N = siz(p);
    vector<vector<int>> G(N);
    for (auto &[u, v] : edge) {
        u = lower_bound(p.begin(), p.end(), u) - p.begin();
        v = lower_bound(p.begin(), p.end(), v) - p.begin();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> vis(N, 0);
    LL ans = 0;
    for (int i = 0;i < N;i ++) {
        if (vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        LL x = 0, y = 0;
        while (siz(q)) {
            int u = q.front(); 
            q.pop();
            x += 1;
            y += siz(G[u]);
            for (int v : G[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        ans += min(x, y / 2);
    }
    cout << ans << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}