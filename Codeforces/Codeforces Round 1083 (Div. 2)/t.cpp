#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL N = 1e6 + 5;
const LL MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n - 1;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<LL>> dp(n + 1, vector<LL> (m + 1, 1)); 
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, u, v);
            for (int i = 0;i <= m;i ++) {
                if ()
            }
        }
    };
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}