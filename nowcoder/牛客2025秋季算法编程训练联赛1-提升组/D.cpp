#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

const LL MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> p(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        if (s[i] == 'B')
            p[i] = 1;
    }
    vector<int> f(n + 1, 0);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto findx = [&](auto findx, int x) -> int {
        if (x != f[x]) {
            f[x] = findx(findx, f[x]);
        }
        return f[x];
    };
    auto merge = [&](int u, int v) -> void {
        u = findx(findx, u);
        v = findx(findx, v);
        if (u == v) return;
        if (u < v) swap(u, v);
        f[u] = v;
    };
    vector<vector<int>> g(n + 1);
    for (int i = 1;i < n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> fa(n + 1, 0);
    vector<int> dp(n + 1, 0);
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        fa[u] = pu;
        if (!p[u]) dp[u] = dp[pu] + 1;
        if (pu) merge(u, pu);
        for (auto v : g[u]) {
            if (v == fa[u]) continue;
            if (p[v]) continue;
            dfs(dfs, u, v);
        }
    };
    // dfs(dfs, 0, 1);
    for (int i = 1;i <= n;i ++) {
        if (p[i]) dfs(dfs, 0, i);
    }
    // for (int i = 1;i <= n;i ++) cout << dp[i] << ' ';
    // cout << '\n';
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        if (p[i]) {
            vector<LL> use;
            LL sum = 1;
            use.push_back(1);
            for (auto v : g[i]) {
                if (!p[v]) {
                    use.push_back(dp[findx(findx, v)]);
                    sum += dp[findx(findx, v)];
                }
            }
            for (LL x : use) {
                sum -= x;
                ans += sum * x;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}