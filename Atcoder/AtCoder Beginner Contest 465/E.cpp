#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

const LL mod = 998244353;

LL f[501][2][3][1024];
// f[位数][lim][模三][bit]

void solve() {
    string N;
    cin >> N;
    int n = siz(N);
    N = ' ' + N;
    vector<int> p(n + 1);
    for (int i = 1;i <= n;i ++) p[i] = N[i] - '0';
    memset(f, 0, sizeof(f));
    f[0][1][0][0] = 1;
    for (int i = 0;i < n;i ++) {
        for (int lim = 0;lim <= 1;lim ++) {
            for (int x = 0;x <= (lim ? p[i + 1] : 9);x ++) {
                for (int b = 0;b < (1 << 10);b ++) {
                    for (int m = 0;m < 3;m ++) {
                        int nlim = lim && x == p[i + 1];
                        int nm = (m + x) % 3;
                        int nb = b || x ? b | (1 << x) : 0;
                        f[i + 1][nlim][nm][nb] += f[i][lim][m][b];
                        f[i + 1][nlim][nm][nb] %= mod;
                    }
                }
            }
        }
    }
    LL ans = 0;
    for (int b = 1;b < (1 << 10);b ++) {
        for (int m = 0;m < 3;m ++) {
            for (int lim = 0;lim <= 1;lim ++) {
                int p = 0;
                if (m == 0) p ++;
                if (__builtin_popcount(b) == 3) p ++;
                if (b >> 3 & 1) p ++;
                if (p == 1 && f[n][lim][m][b]) {
                    ans += f[n][lim][m][b];
                    ans %= mod;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
