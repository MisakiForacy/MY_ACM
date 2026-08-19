#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

#define x first 

#define y second 

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

const int N = 24;

const LL inf = 1e15;

int n;
LL f[N][N], dp[1 << N], use[N];

map<int, set<int>> mp;

void solve() {
    cin >> n;
    for (int i = 0;i < 3 * n;i ++) {
        for (int j = 0;j < 3 * n;j ++) {
            cin >> f[i][j];
        }
    }
    for (int i = 0;i < 1LL << N - 1;i ++) dp[i] = - inf;
    for (int i = 0;i < 3 * n;i ++) {
        for (int j = i + 1;j < 3 * n;j ++) {
            for (int k = j + 1;k < 3 * n;k ++) {
                LL base = (1 << i) + (1 << j) + (1 << k);
                dp[base] = f[i][j] + f[i][k] + f[j][k];
                mp[3].insert(base);
            }
        }
    }
    for (int t = 3;t < 3 * n;t += 3) {
        for (auto base : mp[t]) {
            for (int i = 0;i < 3 * n;i ++) {
                if (base >> i & 1) continue;
                for (int j = i + 1;j < 3 * n;j ++) {
                    if (base >> j & 1) continue;
                    for (int k = j + 1;k < 3 * n;k ++) {
                        if (base >> k & 1) continue;
                        LL mask = ((1 << i) + (1 << j) + (1 << k));
                        dp[mask ^ base] = max(dp[mask ^ base], dp[base] + dp[mask]);
                        mp[t + 3].insert(mask ^ base);
                    }
                }
            }
        }
    }
    cout << dp[(1 << 3 * n) - 1] << '\n';
}

/*
2
0 5 4 -1 -2 -3
5 0 3 -2 -2 -3
4 3 0 -1 -4 -2
-1 -2 -1 0 7 6
-2 -2 -4 7 0 5
-3 -3 -2 6 5 0
*/

int main() {
    // int cnt = 0;
    // int ff[10];
    // memset(ff, 0, sizeof(ff));
    // for (int i = 0;i < (1LL << 24);i ++) {
    //     int ct = __builtin_popcount(i);
    //     if (ct % 3 == 0) cnt ++, ff[ct / 3] ++;
    // }
    // LL tot = 0;
    // for (int i = 3;i <= 24;i += 3) {
    //     LL v = 1;
    //     for (int j = i;j > i - 3;j --) {
    //         v *= j;
    //     }
    //     v /= 6;
    //     tot += v * ff[i / 3];
    //     cout << v << ' ' << ff[i / 3] << '\n';
    // }
    // cout << '\n';
    // cout << tot << '\n';
    // cout << cnt << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}


