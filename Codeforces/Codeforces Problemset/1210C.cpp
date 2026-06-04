#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), dep(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i < n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<LL> q;
    vector<vector<LL>> fa(n + 1, vector<LL> (21, 0));
    vector<vector<LL>> gcd(n + 1, vector<LL> (21, 0));
    vector<vector<LL>> sum(n + 1, vector<LL> (21, 0));
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        fa[u][0] = pu;
        dep[u] = dep[pu] + 1;
        if (siz(g) == 1 && u != 1) q.push(u);
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 1, 0);
    for (int i = 1;i <= n;i ++) gcd[i][0] = a[i];
    for (int i = 1;i <= n;i ++) sum[i][0] = a[i];
    for (int j = 1;j <= 20;j ++) {
        for (int i = 1;i <= n;i ++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            gcd[i][j] = __gcd(gcd[i][j - 1], gcd[fa[i][j - 1]][j - 1]);
            sum[i][j] = sum[i][j - 1] + sum[fa[i][j - 1]][j - 1] + gcd[i][j];
        }
    }
    LL ans = 0;
    vector<int> vis(n + 1, 0);
    while (siz(q)) {
        int u = q.front();
        q.pop();
        if (fa[u][0] != 0) {
            q.push(fa[u][0]);
            vis[fa[u][0]] ++;
        }
        int len = dep[u];
        for (int j = 20;j >= 0;j --) {
            if ((1LL << j) > len) continue;
            len -= 1LL << j;
            ans += (1 - vis[u]) * 
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