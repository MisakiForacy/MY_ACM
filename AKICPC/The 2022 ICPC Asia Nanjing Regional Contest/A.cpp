#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

/*
3
4 5 3
ULDDRR
4 5 0
UUUUUUU
4 5 10
UUUUUUU
*/

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<vector<int>> dp(n + 2, vector<int> (m + 2, 0));
    int l = 0, r = 0, u = 0, d = 0, p = 0, q = 0;
    for (int i = 0;i < siz(s);i ++) {
        if (s[i] == 'U') p --;
        if (s[i] == 'D') p ++;
        if (s[i] == 'L') q --;
        if (s[i] == 'R') q ++;
        u = min(u, p), d = max(d, p);
        l = min(l, q), r = max(r, q);
    }
    u = 1 - u, d = n + 1 - d;
    l = 1 - l, r = m + 1 - r;
    LL use = (d - u) * (r - l);
    if (u >= d || l >= r) {
        if (k == 0) {
            cout << n * m << '\n';
        } else {
            cout << 0 << '\n';
        }
        return;
    }
    int x = 0, y = 0;
    map<pair<int, int>, int> vis;
    dp[u][l] ++, dp[d][r] ++, dp[u][r] --, dp[d][l] --;
    vis[{x, y}] = 1;
    for (int i = 0;i < siz(s);i ++) {
        if (s[i] == 'U') u -= 1, d -= 1, x -= 1;
        if (s[i] == 'D') d += 1, u += 1, x += 1;
        if (s[i] == 'L') l -= 1, r -= 1, y -= 1;
        if (s[i] == 'R') r += 1, l += 1, y += 1;
        if (vis.count({x, y})) continue;
        vis[{x, y}] = 1;
        dp[u][l] ++, dp[d][r] ++, dp[u][r] --, dp[d][l] --;
    }
    LL cnt = 0;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            if (use - dp[i][j] == k) cnt ++;
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << cnt << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.tix", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}