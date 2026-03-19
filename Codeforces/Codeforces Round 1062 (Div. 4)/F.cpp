#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    vector<pair<int,int>> edges;
    for (int i = 1; i < n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }
    vector<int> fa(n + 1, -1), p;
    stack<int> st;
    st.push(1);
    fa[1] = 0;
    while (!st.empty()) {
        int u = st.top(); 
        st.pop();
        p.push_back(u);
        for (int v : g[u]) {
            if (v != fa[u]) {
                fa[v] = u;
                st.push(v);
            }
        }
    }
    vector<int> dp(n + 1, 1);
    for (int i = siz(p) - 1; i >= 0;i --) {
        int u = p[i];
        for (int v : g[u]) {
            if (v != fa[u]) dp[u] += dp[v];
        }
    }
    LL ans = n;
    for (auto [u, v] : edges) {
        if (fa[u] == v) {
            if (dp[u] >= k) ans += n - dp[u];
            if (n - dp[u] >= k) ans += dp[u];
        } else if (fa[v] == u) {
            if (dp[v] >= k) ans += n - dp[v];
            if (n - dp[v] >= k) ans += dp[v];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}