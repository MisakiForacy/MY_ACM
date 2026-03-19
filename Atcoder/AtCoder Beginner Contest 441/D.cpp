#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    LL n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    vector<vector<PII>> g(n + 1);
    map<pair<int, int>, int> C;
    for (int i = 1;i <= m;i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    } 
    set<int> Ans;
    auto dfs = [&](auto dfs, int u, int len, LL Sm) -> void {
        if (len == l) {
            if (s <= Sm && Sm <= t) Ans.insert(u);
            return;
        }
        for (auto [v, w] : g[u]) {
            dfs(dfs, v, len + 1, Sm + w);
        }
    };
    dfs(dfs, 1, 0, 0);
    for (int x : Ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}