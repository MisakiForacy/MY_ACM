#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL mod = 998244353;
const int N = 2e5 + 10;

LL qmi(LL a, LL k) {
    LL res = 1;
    a %= mod;
    if (k < 0) return 0;
    while (k) {
        if (k & 1) res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

LL fac[N], invfac[N];

void init() {
    fac[0] = 1;
    for (int i = 1;i < N;i ++) fac[i] = fac[i - 1] * i % mod;
    invfac[N - 1] = qmi(fac[N - 1], mod - 2);
    for (int i = N - 2;i >= 0;i --) invfac[i] = invfac[i + 1] * (i + 1) % mod;
}

LL C(LL n, LL m) {
    if (n < m) return 0;
    return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

void solve() {
    LL n, m;
    cin >> n >> m;
    LL base = C(m, n - 1);
    LL ans = base * (n - 2) % mod * qmi(2, n - 3) % mod;
    cout << ans << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}