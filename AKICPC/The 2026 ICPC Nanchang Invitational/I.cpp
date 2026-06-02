#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const LL inf = 1e16;

void solve() {
    LL n, x, t0, t1, t2;
    cin >> n >> x;
    cin >> t0 >> t1 >> t2;
    vector<vector<LL>> dp(n + 1, vector<LL> (5, inf));
    dp[0][4] = 0;
    for (int i = 1;i <= n;i ++) {
        char c;
        cin >> c;
        if (c == '0') {
            dp[i][4] = dp[i - 1][4] + t0;
            dp[i][3] = dp[i - 1][3] + t0;
            dp[i][2] = dp[i - 1][2] + t0;
            dp[i][1] = dp[i - 1][1] + t0;
        } else if (c == '1') {
            dp[i][4] = dp[i - 1][4] + t1;
            dp[i][3] = dp[i - 1][3] + t1;
            dp[i][2] = dp[i - 1][2] + t1;
            dp[i][1] = dp[i - 1][1] + t1;
        } else {
            dp[i][4] = dp[i - 1][4] + t2;
            dp[i][3] = dp[i - 1][3] + t2;
            dp[i][2] = dp[i - 1][2] + t2;
            dp[i][1] = dp[i - 1][1] + t2;
        }
        if (i >= x) {
            dp[i][3] = min(dp[i][3], dp[i - x][4]);
            dp[i][2] = min(dp[i][2], dp[i - x][3]);
            dp[i][1] = min(dp[i][1], dp[i - x][2]);
        }
    }
    LL ans = inf;
    for (int i = max(0LL, n - x);i <= n;i ++) {
        ans = min(ans, dp[i][4]);
        ans = min(ans, dp[i][3]);
        ans = min(ans, dp[i][2]);
    }
    ans = min(ans, dp[n][1]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T --) solve();
}

// 1 R
// 2 Y
// 2 R
// 1 G
// 1 Y
// 2 B
// 2 G
// 1 B