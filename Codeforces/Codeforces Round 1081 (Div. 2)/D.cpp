#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n - 1;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<LL> dp(n + 1, 0), sm(n + 1, 0), dep(n + 1, 0), pre(n + 1, 0), add(n + 1, 0), mx1(n + 1, 0), mx2(n + 1, 0);
    // dp[u] 表示以u为子树根时最大答案
    // sm[u] 表示以u为根时子树的和
    // pre[u] 表示以u为根时子树和的和
    // add[u] 表示以u为根时，以dp[u]为答案时，子树中被切断的小子树和
    // mx1[u] 表示以u为根时子树最大的深度
    // mx2[u] 表示以u为根时子树次大的深度
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        sm[u] = a[u];
        dep[u] = dep[pu] + 1;
        vector<int> use;
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, u, v);
            sm[u] += sm[v];
            pre[u] += pre[v] + sm[v];
            use.push_back(mx1[v]);
        }
        sort(all(use), greater());
        if (siz(use) > 1) mx1[u] = use[0], mx2[u] = use[1];
        else if (siz(use) == 1) mx1[u] = use[0];
        else mx1[u] = dep[u];
    };
    auto get = [&](auto get, int pu, int u) -> void {
        for (auto v : g[u]) {
            if (v == pu) continue;
            get(get, u, v);
            dp[u] = max(dp[u], pre[u] - pre[v] + dp[v]);
            if (mx1[v] == mx1[u]) {
                dp[u] = max(dp[u], pre[u] + sm[v] * (mx2[u] - dep[u]));
            } else {
                dp[u] = max(dp[u], pre[u] + sm[v] * (mx1[u] - dep[u]));
            }
        }
    };
    dfs(dfs, 0, 1);
    get(get, 0, 1);
    // for (int i = 1;i <= n;i ++) cout << pre[i] << ' ';
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