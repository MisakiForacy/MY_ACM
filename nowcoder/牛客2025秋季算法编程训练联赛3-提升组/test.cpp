#include <bits/stdc++.h>
using namespace std;
using LL = long long;


/*

dp[i][j] 表示走到当前格子的最大值
则dp的转移式为dp[i][j] = max(dp[i][j], 
                    dp[i - 1][j] + a[i][j], 
                    dp[i][j - 1] + a[i][j]);

*/

int main () {
    LL n, m;
    cin >> n >> m;
    LL a [n + 1][m + 1];
    LL dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            dp[i][j] = max({ dp[i][j], 
                dp[i - 1][j] + a[i][j], 
                dp[i][j - 1] + a[i][j]
            });
        }
    }
    cout << dp[n][m] << '\n';
}