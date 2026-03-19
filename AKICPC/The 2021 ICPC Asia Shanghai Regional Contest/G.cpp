#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;

const LL N = 2e5 + 10;
const LL MOD = 998244353;

vector<LL> fac(N, 0), invfac(N, 0);
vector<LL> CC(N, 0);

/*
7
1 2
1 3
1 7
4 7
5 7
6 7
*/

LL inv(LL a) {
    LL k = MOD - 2;
    LL res = 1;
    while (k) {
        if (k & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        k >>= 1;
    }
    return res;
}

void init() {
    fac[0] = invfac[0] = 1;
    for (int i = 1;i < N;i ++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    invfac[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 1; --i) {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
}

LL cal(LL n, LL m) {
    if (n < m) return 1;
    return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

void iinit() {
    CC[0] = 1;
    for (int i = 2;i < N;i += 2) {
        CC[i] = CC[i - 2] * cal(i, 2) % MOD;
    }
    for (int i = 2;i < N;i += 2) {
        CC[i] *= invfac[i / 2];
        CC[i] %= MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i < n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    g[0].push_back(1), g[1].push_back(0);
    vector<LL> dp(n + 1, 1), fa(n + 1, 0), son(n + 1, 0);
    for (int i = 1;i <= n;i ++) son[i] = siz(g[i]) - 1;
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        fa[u] = pu;
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, u, v);
            dp[u] = dp[u] * dp[v] % MOD;
        }
        if (son[u] & 1) {
            dp[u] *= son[u] * CC[son[u] - 1] % MOD;
            dp[u] %= MOD;
            son[pu] -= 1;
        } else if (son[u] != 0) {
            dp[u] *= CC[son[u]];
            dp[u] %= MOD;
        }
    };
    dfs(dfs, 0, 1);
    // for (int i = 1;i <= n;i ++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    cout << dp[1] << '\n';
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    init();
    iinit();
    // for (int i = 0;i < 10;i += 2) {
    //     cout << CC[i] << ' ';
    // }
    // cout << '\n';
    // cout << cal(2, 2) << '\n';
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}