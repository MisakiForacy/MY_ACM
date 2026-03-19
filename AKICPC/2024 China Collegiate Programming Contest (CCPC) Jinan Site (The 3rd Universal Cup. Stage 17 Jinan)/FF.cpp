#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL MOD = 998244353;
const int N = 2e5 + 10;
const int LOG = 20;

LL inv (LL a) {
    LL res = 1;
    LL k = MOD - 2;
    while (k) {
        if (k & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        k >>= 1;
    }
    return res;
}

LL fac[N], invfac[N];

void init () {
    fac[0] = invfac[0] = 1;
    for (int i = 1;i < N;i ++) fac[i] = fac[i - 1] * i % MOD;
    invfac[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2;i >= 0;i --) invfac[i] = invfac[i + 1] * (i + 1) % MOD;
}

LL cal (LL n, LL m) {
    if (m > n) return 0;
    return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

LL dp[N][LOG];

void solve () {
    LL m, n;
    cin >> m >> n;
    LL ans = cal (m, n) * n % MOD;
    for (int i = 1;i <= m;i ++) dp[i][1] = 1;
    for (int k = 2;k < LOG;k ++) {
        for (int i = 1;i <= m;i ++) {
            for (int j = i + i;j <= m;j += i) {
                dp[j][k] += dp[i][k - 1];
                dp[j][k] %= MOD;
            }
        }
    }
    for (int i = 1;i <= m;i ++) {
        for (int j = 1;j <= LOG;j ++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    LL ret = 0;
    for (int i = 1;i <= m;i ++) {
        for (int j = 1;j < LOG;j ++) {
            ret += dp[i][j] * cal (m / i - 1, n - j) % MOD;
            ret %= MOD;
        }
    }
    cout << (ans - ret + MOD) % MOD << '\n';
}

int main () {
    init ();
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}