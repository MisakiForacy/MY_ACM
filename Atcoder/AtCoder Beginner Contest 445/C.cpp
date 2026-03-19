#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

// int m = 99;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1, 0), dp(n + 1, 0);
    queue<PLL> q;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i ++) {
        cin >> p[i];
        if (p[i] == i) q.push({i, i});   
        else {
            g[p[i]].push_back(i);
        } 
    }
    while (siz(q)) {
        auto [u, fa] = q.front();
        q.pop();
        dp[u] = fa;
        for (auto v : g[u]) {
            q.push({v, fa});
        }
    }
    for (int i = 1;i <= n;i ++) cout << dp[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}