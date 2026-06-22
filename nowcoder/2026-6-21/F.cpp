#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

const LL inf = 1e15;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n - 1;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> f(n + 1, 0), col(n + 1, 0), cnt(n + 1, 0);
    vector<int> dep(n + 1, 0), fa(n + 1, 0);
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        fa[u] = pu;
        dep[u] = dep[pu] + 1;
        if (siz(g[u]) == 1) {
            if (s[u] == '1') col[u] = 1, cnt[u] = 1;
        }
        int use = 0;
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u);
            if (col[v]) {
                col[u] += col[v];
                cnt[u] += cnt[v];
                use ++;
            }
        }
        if (use && s[u] != '1') col[u] += 1;
        f[u] = col[u] - cnt[u];
    };
    
    dfs(dfs, 1, 0);
    while (q --) {
        int x, y;
        cin >> x >> y;
        if (fa[x] == y) swap(x, y);
        cout << f[y] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
