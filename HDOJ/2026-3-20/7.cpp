#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;

const int N = 1e6 + 10;

LL a[N], f[N], fa[N], sm[N], sz[N];
vector<int> g[N];

void dfs(int pu, int u) {
    fa[u] = pu;
    sm[u] = a[u];
    if (siz(g[u]) == 1 && u != 1) {
        f[u] = a[u];
        return;
    }
    f[u] = inf;
    for (auto v : g[u]) {
        if (v == pu) continue;
        dfs(u, v);
        sz[u] += sz[v];
        sm[u] += sm[v];
        f[u] = min(f[u], f[v]);
    }
    f[u] = min(f[u], sm[u] / sz[u]);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i ++) sz[i] = 1;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n - 1;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    dfs(0, 1);
    for (int i = 1;i <= n;i ++) cout << f[i] << ' ';
    cout << '\n';
    for (int i = 1;i <= n;i ++) a[i] = f[i] = fa[i] = sm[i] = sz[i] = 0;
    for (int i = 1;i <= n;i ++) g[i].clear();
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}