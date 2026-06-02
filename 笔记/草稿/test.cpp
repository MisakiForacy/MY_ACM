#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 1);
    LL dp[n + 1][2][2];
    for (int i = 1;i <= n;i ++) cin >> a[i];
    dp[0][0][0] = 1;
    for (int i = 1;i <= n;i ++) {
        if (i == 1) {
            if (a[i] == 1) {
                dp[i][0][0] += dp[i - 1][0][0];
                dp[i][1][0] += dp[i - 1][0][0];
            } else if (a[i] == 2) {
                dp[i][1][0] += dp[i - 1][0][0];
            }
        } else if (i >= 2) {
            if (a[i] == 1) {
                dp[i][1][0] += dp[i - 1][0][0];
                dp[i][1][0] += dp[i - 1][0][1];
                dp[i][0][1] += dp[i - 1][1][0];
                dp[i][0][1] += dp[i - 1][1][1];
                dp[i][0][0] += dp[i - 1][0][0];
                dp[i][0][0] += dp[i - 1][0][1];
            } else if (a[i] == 2) {
                dp[i][0][1] += dp[i - 1][1][0];
                dp[i][0][1] += dp[i - 1][1][1];
                dp[i][1][0] += dp[i - 1][0][0];
                dp[i][1][0] += dp[i - 1][0][1];
                dp[i][1][1] += dp[i - 1][1][0];
                dp[i][1][1] += dp[i - 1][1][1];
            } else {
                dp[i][1][1] += dp[i - 1][1][0];
                dp[i][1][1] += dp[i - 1][1][0];
            }
        }
    }
    LL ans = dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}