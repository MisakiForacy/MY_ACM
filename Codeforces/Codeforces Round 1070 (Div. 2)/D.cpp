#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1), d(n + 1, 0);
    vector<vector<int>> g(n + 1);
    vector<map<LL, int>> dp(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        dp[v][a[u]] ++;
        if (a[u] < a[v]) {
            g[u].push_back(v);
            d[v] ++;
        }
    }
    vector<int> vis(n + 1, 0);
    stack<int> que;
    for (int i = 1;i <= n;i ++) 
        if (!d[i])
            que.push(i);
    LL Ans = m;    
    while (siz(que)) {
        int u = que.top();
        que.pop();
        for (int v : g[u]) {
            d[v] -= 1;
            Ans += dp[u][a[v] - a[u]];
            Ans %= MOD;
            dp[v][a[u]] += dp[u][a[v] - a[u]];
            dp[v][a[u]] %= MOD;
            if (!d[v]) que.push(v);
        }
    }
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}