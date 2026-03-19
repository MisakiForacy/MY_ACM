#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL MOD = 1006903069;
const LL inf = 1e18;

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<vector<LL>> a(n + 1, vector<LL> (m + 1, inf));
    vector<LL> g(m + 1);
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= m;i ++) cin >> g[i];
    auto run1 = [&]() -> LL {
        vector<LL> dp(1LL << n, inf);
        dp[0] = 0;
        for (int i = 1;i <= m;i ++) {
            vector<LL> ndp = dp;
            for (int j = 0;j < 1LL << n;j ++) {
                for (int k = 1;k <= n;k ++) {
                    if (j >> (k - 1) & 1) {
                        ndp[j] = min(ndp[j], ndp[j - (1LL << k - 1)] + a[k][i]);
                    }
                }
            }
            for (int j = 0;j < 1LL << n;j ++) {
                dp[j] = min(dp[j], ndp[j] + g[i]);
            }
        }
        return dp[(1LL << n) - 1];
    };
    auto run2 = [&]() -> LL {
        LL Mi = inf;
        for (int k = 1;k < 1LL << m;k ++) {
            LL sum = 0;
            vector<int> use(m + 1, 0);
            for (int i = 1;i <= n;i ++) {
                LL mi = inf, id = 0;
                for (int j = 1;j <= m;j ++) {
                    if (k >> (j - 1) & 1) {
                        if (a[i][j] < mi) mi = a[i][j], id = j;
                    }
                }
                use[id] = 1;
                sum += mi;
            }
            for (int i = 1;i <= m;i ++) sum += use[i] * g[i];
            Mi = min(Mi, sum);
        }
        return Mi;
    };
    if (m <= 16) {
        cout << run2() << '\n';
    } else {
        cout << run1() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}