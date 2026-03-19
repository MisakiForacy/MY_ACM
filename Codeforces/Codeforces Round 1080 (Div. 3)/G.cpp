#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e18;
const int N = 2e5 + 10;
const LL MOD = 1e9 + 7;
 
void solve() {
    int n, q, cnt = 0;
    cin >> n >> q;
    vector<int> L(n + 1, 0), R(n + 1, 0), dep(n + 1, 0);
    vector<vector<int>> fa(21, vector<int> (n + 1, 0));
    for (int i = 1;i <= n;i ++) cin >> L[i] >> R[i], fa[0][L[i]] = fa[0][R[i]] = i;
    vector<LL> dp(n + 1, 0), sz(n + 1, 1), dfn = {0};
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        sz[u] = 1;
        dep[u] = dep[pu] + 1;
        if (L[u]) {
            dfn.push_back(u);
            dfs(dfs, u, L[u]);
            dfn.push_back(u);
            dfs(dfs, u, R[u]);
            dfn.push_back(u);
            sz[u] += sz[L[u]], sz[u] += sz[R[u]];
        } else {
            dfn.push_back(u);
        }
    };
    auto get = [&](auto get, int pu, int u) -> void {
        dp[u] = dp[pu] + (sz[u] - 1) * 2 + 1;
        dp[u] %= MOD;
        if (R[u]) get(get, u, L[u]);
        if (L[u]) get(get, u, R[u]);
    };
    dfs(dfs, 0, 1);
    get(get, 0, 1);
    vector<int> pp(n + 1, 0);
    for (int i = 1;i < siz(dfn);i ++) {
        if (!pp[dfn[i]]) pp[dfn[i]] = i;
    }
    sz[0] = sz[1];
    pp[0] = 0;
    for (int j = 1;j <= 20;j ++) {
        for (int i = 1;i <= n;i ++) {
            fa[j][i] = fa[j - 1][fa[j - 1][i]];
        }
    }
    vector<vector<LL>> up(21, vector<LL> (n + 1, 0));
    for (int i = 1;i <= n;i ++) up[0][i] = sz[i] * 2 - 1;
    for (int j = 1;j <= 20;j ++) {
        for (int i = 1;i <= n;i ++) {
            int u = fa[j - 1][i];
            up[j][i] = up[j - 1][i] + up[j - 1][u];
        }
    }
    while (q --) {
        LL v, k;
        cin >> v >> k;
        int u = v, jmp = 0;
        for (int j = 20; j >= 0; --j) {
            if (fa[j][u] && k >= up[j][u]) {
                k -= up[j][u];
                u = fa[j][u];
            }
        }
        cout << dfn[pp[u] + k] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}