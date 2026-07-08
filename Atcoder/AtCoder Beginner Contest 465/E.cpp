#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

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
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        for (int b = 0;b < (1 << 10);b ++) {
            if (__builtin_popcountll(b) >= i) continue;
            for (int x = 0;x <= (i == 1 ? p[i] : 9);x ++) {
                if (b == 0 && x == 0) continue;
                f[i][(i == 1 && x == p[i])][x % 3][b | (1 << x)] ++;
            }
        }
        for (int lim = 0;lim <= 1;lim ++) {
            for (int b = 0;b < (1 << 10);b ++) {
                if (__builtin_popcountll(b) >= i) continue;
                for (int x = 0;x <= (lim ? p[i] : 9);x ++) {
                    for (int m = 0;m < 3;m ++) {
                        if (b == 0 && x == 0) {
                            f[i][lim && x == p[i]][(m + x) % 3][b] += f[i - 1][lim][m][b];
                        } else {
                            f[i][lim && x == p[i]][(m + x) % 3][b | (1 << x)] += f[i - 1][lim][m][b];
                        }
                    }
                }
            }
        }
    }
    for (int lim = 0;lim <= 1;lim ++) {
        for (int b = 0;b < (1LL << 10);b ++) {
            for (int m = 0;m < 3;m ++) {
                if (m && (b >> 3 & 1) && __builtin_popcountll(b) != 3) ans += f[n][lim][m][b];
                if (!m && !(b >> 3 & 1) && __builtin_popcountll(b) != 3) ans += f[n][lim][m][b];
                if (m && !(b >> 3 & 1) && __builtin_popcountll(b) == 3) ans += f[n][lim][m][b];
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
