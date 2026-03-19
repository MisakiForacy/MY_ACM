#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define int long long

using namespace std;
using LL = long long;

const LL N = 1e6 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(n);
    vector<vector<int>> g(n + 1);
    for (int i = 0;i < n;i ++) {
        cin >> p[i].x >> p[i].y;
        g[p[i].y].push_back(p[i].x);
    }
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> dp(n + 2, 0), Mi(n + 2, 0), ok(n + 2, 0);
    // dp[i] 表示所有的y都大于等于i，的前i + 1项的最大值
    for (int i = n;i >= 0;i --) {
        dp[i] = dp[i + 1];
        while (siz(q) > i + 1) dp[i] = dp[i] - q.top(), q.pop();
        for (int x : g[i]) {
            if (siz(q) == i + 1 && x > q.top()) {
                dp[i] = dp[i] - q.top() + x;
                q.pop();
                q.push(x);
            } else if (siz(q) < i + 1) {
                dp[i] = dp[i] + x;
                q.push(x);
            }
        }
        ok[i] = (siz(q) == i + 1); 
        if (siz(q)) Mi[i] = q.top();
        // cout << dp[i] << ' ' << Mi[i] << '\n';
    }
    vector<int> Mx1(n + 1, 0), Mx2(n + 1, 0), Mx3(n + 1, 0);
    Mx1[0] = dp[0], Mx2[0] = (!ok[0] ? dp[0] : 0), Mx3[0] = (ok[0] ? dp[0] - Mi[0] : 0);
    for (int i = 1;i <= n;i ++) Mx1[i] = max(Mx1[i - 1], dp[i]);
    for (int i = 1;i <= n;i ++) {
        if (!ok[i]) 
            Mx2[i] = max(Mx2[i - 1], dp[i]);
        else 
            Mx2[i] = Mx2[i - 1];    
    }
    for (int i = 1;i <= n;i ++) {
        if (ok[i]) 
            Mx3[i] = max(Mx3[i - 1], dp[i] - Mi[i]);
        else 
            Mx3[i] = Mx3[i - 1];    
    }
    while (m --) {
        int x, y;
        cin >> x >> y;
        cout << max({Mx1[n], Mx2[y] + x, Mx3[y] + x, x}) << ' ';
        // // cout << max(dp[y] - Mi[y] + x, dp[y]) << ' ';
        // if (ok[y]) {
        //     cout << max(dp[y] - Mi[y] + x, dp[y]) << ' ';
        // } else {
        //     cout << dp[y] + x << ' ';
        // }
    }
    cout << '\n';
}

/*
1 2
6 1
7 0
8 1
*/

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}