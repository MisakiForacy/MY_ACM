#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0), p(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i], p[i] = i;
    for (int i = 1;i <= n;i ++) {
        g[i].push_back(a[i]);
    }
    LL len;
    vector<int> vis(n + 1, 0);
    auto dfs = [&](auto dfs, int u) -> void {
        len ++;
        vis[u] = 1;
        for (auto v : g[u]) {
            if (!vis[v])
                dfs(dfs, v);
        }
    };
    LL Ans = 0;
    for (int i = 1;i <= n;i ++) {
        if (!vis[i]) {
            len = 0;
            dfs(dfs, i);
            Ans += (len - 1) * len / 2;
        }
    }
    cout << Ans << '\n';
}