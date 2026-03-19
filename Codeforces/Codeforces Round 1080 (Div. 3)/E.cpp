#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const int N = 2e5 + 10;
const LL inf = 1e18;
const LL MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<PLL> p(n + 1);
    for (int i = 1;i <= n;i ++) cin >> p[i].x >> p[i].y;
    vector<LL> dp(n + 1, 0), sz(n + 1, 0);
    auto dfs = [&](auto dfs, int u) -> void {
        sz[u] = 1;
        if (p[u].x) dfs(dfs, p[u].x), sz[u] += sz[p[u].x];
        if (p[u].y) dfs(dfs, p[u].y), sz[u] += sz[p[u].y];
    };
    auto get = [&](auto get, int pu, int u) -> void {
        dp[u] = dp[pu] + (sz[u] - 1) * 2 + 1;
        dp[u] %= MOD;
        if (p[u].x) get(get, u, p[u].x);
        if (p[u].y) get(get, u, p[u].y);
    };
    dfs(dfs, 1);
    get(get, 0, 1);
    // for (int i = 1;i <= n;i ++) cout << sz[i] << ' ';
    // cout << '\n';
    for (int i = 1;i <= n;i ++) cout << dp[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}