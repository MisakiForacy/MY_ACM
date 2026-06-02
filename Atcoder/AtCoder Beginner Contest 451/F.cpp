#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

int n, q, u, v, cnt, c = 1;
int ok = 1, flip;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    vector<int> f(n + 1, 0), col(n + 1, -1), sz(n + 1, 1), b(n + 1, 0), vis(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto find = [&](auto find, int x) -> int {
        return (f[x] == x ? f[x] : find(find, f[x]));
    };
    auto merge = [&](int u, int v) -> void {
        u = find(find, u);
        v = find(find, v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u, v);
        f[u] = v, sz[v] += sz[u], b[v] += b[u];
    };
    auto dfs = [&](auto dfs, int u, int c) -> void {
        vis[u] = c;
        col[u] = !col[u];
        for (auto v : g[u]) {
            if (vis[v] == c) continue;
            dfs(dfs, v, c);
        }
    };
    for (int i = 1;i <= q;i ++) {
        flip = 0;
        cin >> u >> v;
        if (!ok) {
            cout << -1 << '\n';
            continue;
        } else if (find(find, u) == find(find, v)) {
            if (col[u] == col[v]) {
                cout << -1 << '\n';
                ok = 0;
            } else {
                cout << cnt << '\n';
            }
        } else {
            cnt -= min(sz[find(find, u)] - b[find(find, u)], b[find(find, u)]);
            cnt -= min(sz[find(find, v)] - b[find(find, v)], b[find(find, v)]);
            if (col[u] == -1 && col[v] == -1) {
                col[u] = 1, col[v] = 0;
                b[u] = 1;
            } else if (col[u] == -1) {
                col[u] = !col[v], b[u] += col[u];
            } else if (col[v] == -1) {
                col[v] = !col[u], b[v] += col[v];
            }
            if (col[u] == col[v]) {
                if (sz[find(find, u)] < sz[find(find, v)]) {
                    b[find(find, u)] = sz[find(find, u)] - b[find(find, u)];
                    dfs(dfs, u, c ++);
                } else {
                    b[find(find, v)] = sz[find(find, v)] - b[find(find, v)];
                    dfs(dfs, v, c ++);
                }
            }
            merge(u, v);
            cnt += min(sz[find(find, u)] - b[find(find, u)], b[find(find, u)]);
            cout << cnt << '\n';
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
}