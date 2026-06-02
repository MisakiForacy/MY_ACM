#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL mod = 998244353;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    LL n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    for (int i = 1;i <= n;i ++) {
        char c;
        cin >> c;
        p[i] = c - '0';
    }
    int id = 0;
    vector<vector<LL>> dp(k + 1, vector<LL> (k + 1, 0));
    dp[0][1] = 1;
    for (int i = 1;i <= n;i ++) {
        vector<LL> use(k + 1, 0);
        LL tot = 0;
        vector<vector<LL>> ndp(k + 1, vector<LL> (k + 1, 0));
        for (int j = 0;j <= k;j ++) {
            for (int t = 1;t < k;t ++) {
                use[j] += dp[j][t];
                use[j] %= mod;
            }
            tot += use[j];
            tot %= mod;
        }
        if (p[i] == 0) {
            for (int j = 1;j <= k;j ++) {
                for (int t = 0;t < k - 1;t ++) {
                    if (t) {
                        ndp[j][t + 1] += dp[j][t];
                        ndp[j][t + 1] %= mod;
                    } else { 
                        for (int jj = 0;jj <= k;jj ++) {
                            if (jj == j) continue;
                            ndp[j][1] += use[jj];
                            ndp[j][1] %= mod;
                        }
                    }
                }
            }
        } else {
            for (int j = 0;j <= k;j ++) {
                if (j == p[i]) {
                    for (int t = 0;t < k - 1;t ++) {
                        ndp[p[i]][t + 1] += dp[j][t];
                        ndp[p[i]][t + 1] %= mod;
                    }
                } else {
                    for (int t = 1;t < k;t ++) {
                        ndp[p[i]][1] += dp[j][t];
                        ndp[p[i]][1] %= mod;
                    }
                }
            }
        }
        dp = ndp;
    }
    LL ans = 0;
    for (int i = 1;i <= k;i ++) {
        for (int j = 1;j < k;j ++) {
            ans += dp[i][j];
            ans %= mod;
        }
    }
    cout << ans << '\n';
}