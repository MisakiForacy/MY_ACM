#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> fa(n + 1, 0), col(n + 1), chg(n + 1, 0);
    vector<vector<int>> son(n + 1);
    for (int i = 2;i <= n;i ++) cin >> fa[i], son[fa[i]].push_back(i); 
    for (int i = 1;i <= n;i ++) {
        char c;
        cin >> c;
        col[i] = c - '0';
    }
    int q;
    cin >> q;
    while (q --) {
        int a;
        cin >> a;
        chg[a] ^= 1;
    }
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        chg[u] ^= chg[pu];
        col[u] ^= chg[u];
        for (auto v : son[u]) {
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 1, 0);
    for (int i = 1;i <= n;i ++) cout << col[i];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}