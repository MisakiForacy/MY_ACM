#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

struct node
{
    int u, w;
    bool operator < (const node&T) const {
        return T.w < w;
    }
};


void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> g(n + 1);
    vector<int> disl(n + 1, 10 * n), disr(n + 1, 10 * n);
    vector<int> visl(n + 1, 0), visr(n + 1, 0);
    map<pair<int, int>, int> mp;
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u, v}] = mp[{v, u}] = 1;
    }
    queue<int> q1, q2;
    q1.push(s), q2.push(t);
    disl[s] = disr[t] = 0;
    visl[s] = visr[t] = 1;
    while (siz(q1)) {
        int u = q1.front();
        q1.pop();
        for (auto v : g[u]) {
            if (!visl[v]) {
                disl[v] = disl[u] + 1;
                visl[v] = 1;
                q1.push(v);
            }
        }
    }
    while (siz(q2)) {
        int u = q2.front();
        q2.pop();
        for (auto v : g[u]) {
            if (!visr[v]) {
                disr[v] = disr[u] + 1;
                visr[v] = 1;
                q2.push(v);
            }
        }
    }
    int ans = 0;
    int mi = disr[s];
    for (int i = 1;i <= n;i ++) {
        for (int j = i + 1;j <= n;j ++) {
            if (mp.count({i, j}) || i == j) continue;
            if (disl[i] + disr[j] + 1 >= mi && disr[i] + disl[j] + 1 >= mi) {
                // cout << disl[i] << ' ' << disr[i] << ' ';
                // cout << i << ' ' << j << '\n';
                ans ++;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}