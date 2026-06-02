#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, rt;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        if (x) g[x].push_back(i);
        else   rt = i;
    }
    int mx = 0, ok = 1;
    for (int i = 1;i <= n;i ++) mx = max(mx, siz(g[i]));
    for (int i = 1;i <= n;i ++) if (siz(g[i]) != mx && siz(g[i]) != 0) ok = 0;
    cout << mx << ' ' << (ok ? "yes\n" : "no\n");
    int cnt = 0;
    auto dfs = [&](auto dfs, int u) -> void {
        cout << u;
        cnt ++;
        if (cnt == n) cout << '\n';
        else          cout << ' ';
        for (auto v : g[u]) {
            dfs(dfs, v);
        }
    };
    dfs(dfs, rt);
}

int main() {
    // cout << fixed << setprecision(2);
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}