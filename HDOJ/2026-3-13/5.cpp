#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<LL> a(n + 1), p(n + 1, 0);
    vector<vector<LL>> dp(n + 1, vector<LL> (k + 2, 0));
    // dp[i][j] 表示取到第i位，包括自己，后面有j个a[i] / 2
    // dp[i][j] = dp[i - m - 1][]
    for (int i = 1;i <= n;i ++) cin >> a[i], p[i] = p[i - 1] + a[i];
    for (int i = 1;i <= n;i ++) {
        for (int j = 0;j <= k + 1;j ++) {
            if (j == 0) {
                for (int )
            } else if (j <= k) {

            } else {
                dp[i][k + 1] = dp[]
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}