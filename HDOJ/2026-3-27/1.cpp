#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL mod = 998244353;

/*
f[i][j][k][x][y]
第i位，j表示前缀是否等于s前缀(1/0)，k表示前缀是否等于t前缀(1/0)
x表示当前位a等于0/1, y表示当前位b等于0/1
满足a为b的子集的方案数
(ai = 0 && bi = 1, ai = 1 && bi = 1, ai = 0 && bi = 0)
的方案数
ans = f[n][0~1][0~1][0~1][0~1][1] * 2 - (t - s + 1)
其中[x][y] 满足 (y >= x)
*/

void solve() {
    string s, t;
    cin >> s >> t;
    while (siz(s) < siz(t)) s = '0' + s;
    int n = siz(s);
    s = ' ' + s, t = ' ' + t;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i ++) {
        a[i] = s[i] - '0';
        b[i] = t[i] - '0';
    }
    LL S = 0, T = 0, p = 1;
    for (int i = n;i >= 1;i --) {
        if (a[i]) S += p, S %= mod;
        if (b[i]) T += p, T %= mod;
        p *= 2;
        p %= mod;
    }
    LL f[n + 1][2][2][2][2];
    memset(f, 0, sizeof f);
    f[0][1][1][0][0] = 1;
    for (int i = 1;i <= n;i ++) {
        int lx = a[i - 1], ly = b[i - 1];
        int xx = a[i], yy = b[i];
        // for (int y = 0;y <= yy;y ++) {
        //     for (int x = 0;x <= y;x ++) {
        //         if (x == xx && y == yy) {
        //             f[i][1][1][x][y] += f[i - 1][1][1][lx][ly];
        //             f[i][1][0][x][y] += f[i - 1][1][0][lx][0];
        //             f[i][1][0][x][y] += f[i - 1][1][0][lx][1];
        //             f[i][0][1][x][y] += f[i - 1][0][1][0][ly];
        //             f[i][0][1][x][y] += f[i - 1][0][1][1][ly];
        //         } else if (x == xx) {
        //             f[i][1][0][x][y] += f[i - 1][1][1][lx][ly];
        //             f[i][1][0][x][y] += f[i - 1][1][0][lx][0];
        //             f[i][1][0][x][y] += f[i - 1][1][0][lx][1];
        //         } else if (y == yy) {
        //             f[i][0][1][x][y] += f[i - 1][1][1][lx][ly];
        //             f[i][0][1][x][y] += f[i - 1][0][1][0][ly];
        //             f[i][0][1][x][y] += f[i - 1][0][1][1][ly];
        //         }
        //         for (int t = 0;t < 16;t ++) 
        //             f[i][0][0][x][y] += f[i - 1][t >> 3 & 1][t >> 2 & 1][t >> 1 & 1][t & 1];
        //     }
        // }
        // for (int t = 0;t < 16;t ++) 
        //     f[i][t >> 3 & 1][t >> 2 & 1][t >> 1 & 1][t & 1] %= mod;
        f[i][1][1][xx][yy] += f[i - 1][1][1][lx][ly];
        for (int y = 0;y <= yy;y ++) {
            for (int x = 0;x <= y;x ++) {
                if (x > xx) {
                    if (y == yy) {
                        f[i][0][1][x][y] += f[i - 1][1][1][lx][ly];
                        f[i][0][1][x][y] += f[i - 1][0][1][lx][ly];
                        f[i][0][1][x][y] += f[i - 1][0][1][lx][ly];
                        f[i][0][0][x][y] += f[i - 1][1][0][lx][ly];
                        f[i][0][0][x][y] += f[i - 1][0][0][lx][ly];
                    } else {
                        f[i][0][1][x][y] += f[i - 1][1][1][lx][ly];
                        f[i][0][1][x][y] += f[i - 1][0][1][lx][ly];
                        f[i][0][0][x][y] += f[i - 1][1][0][lx][ly];
                        f[i][0][0][x][y] += f[i - 1][0][0][lx][ly];    
                    }
                } 
                if (y < yy) {
                    if (x == xx) {
                        f[i][1][0][x][y] += f[i - 1][1][1][lx][ly];
                        f[i][1][0][x][y] += f[i - 1][1][0][lx][ly];
                    } else {

                    }
                }
            }
        }
    }
    LL ans = 0;
    for (int t = 0;t < 16;t ++) {
        ans += f[n][t >> 3 & 1][t >> 2 & 1][t >> 1 & 1][t & 1];
        ans %= mod;    
    }
    cout << S << ' ' << T << '\n';
    // ans += ((T - S + mod) % mod) % mod;
    ans += mod;
    ans %= mod;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}