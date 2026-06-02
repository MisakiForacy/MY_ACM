#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<LL> p(n + 1), vis(n + 1, 0), q(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i ++) {
        cin >> p[i];
        g[i].push_back(p[i]);
    }
    vector<int> Tp;
    auto dfs = [&](auto dfs, int u) -> void {
        vis[u] = 1;
        Tp.push_back(u);
        for (int v : g[u]) {
            if (vis[v]) continue;
            dfs(dfs, v);
        }
    };
    set<vector<int>> use;
    vector<vector<int>> even;
    for (int i = 1;i <= n;i ++) {
        if (!vis[i]) {
            Tp.clear();
            dfs(dfs, i);
            if (siz(Tp) & 1) {
                use.insert(Tp);
            } else {
                even.push_back(Tp);
            }
        }
    }
    for (auto vec : use) {
        if (siz(vec) & 1) {
            int t = siz(vec) + 1 >> 1;
            for (int j = 0;j < siz(vec);j ++) {
                q[vec[j]] = vec[(j + t) % siz(vec)];
            }
        }
    }
    sort(all(even), [&](vector<int> a, vector<int> b) {
        return siz(a) < siz(b);
    });
    if (siz(even) % 2) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0;i < siz(even);i += 2) {
        if (siz(even[i]) != siz(even[i + 1])) {
            cout << -1 << '\n';
            return;
        }
        for (int j = 0;j < siz(even[i]);j ++) {
            q[even[i][j]] = even[i + 1][j];
            q[even[i + 1][j]] = even[i][(j + 1) % siz(even[i])];
        }
    }
    for (int i = 1;i <= n;i ++) cout << q[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}