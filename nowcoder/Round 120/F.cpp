#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL MOD = 998244353;

void solve () {
    LL n, l, r;
    cin >> n >> l >> r;
    LL L = l, R = r;
    string s;
    cin >> s;
    s = ' ' + s + s;
    if (r == l) {
        l = (l - 1) % n + 1;
        cout << s[l] << '\n';
        return;
    }
    if (r - l + 1 <= n) {
        l = (l - 1) % n + 1;
        r = (r - 1) % n + 1;
        if (r <= l) r += n;
        LL Ans = 0;
        for (int i = l;i <= r;i ++) {
            Ans *= 10;
            Ans += s[i] - '0';
            Ans %= MOD;
        }
        cout << Ans << '\n';
        return;
    }
    l = (l - 1) % n + 1;
    r = (r - 1) % n + 1;
    LL Ans = 0;
    for (int i = l;i <= n;i ++) {
        Ans *= 10;
        Ans += s[i] - '0';
        Ans %= MOD;
    }
    LL p = 0, p10 = 1;
    for (int i = 1;i <= n;i ++) {
        p = (p * 10 + s[i] - '0') % MOD;
        p10 = p10 * 10 % MOD;
    }
    LL k = ((R - L + 1) - (n - l + 1) - r) / n;
    auto qmi = [&](LL a, LL k) -> LL {
        LL res = 1;
        a %= MOD;
        while (k) {
            if (k & 1) (res *= a) %= MOD;
            (a *= a) %= MOD;
            k >>= 1;
        }
        return res;
    };
    if (k > 0) {
        Ans = Ans * qmi(p10, k) % MOD;
        LL use = (p10 - 1 + MOD) % MOD;
        LL inv = qmi(use, MOD - 2);
        LL V = (qmi(p10, k) - 1 + MOD) % MOD * inv % MOD;
        Ans = Ans + p * V;
        Ans %= MOD;
    }
    for (int i = 1;i <= r;i ++) {
        Ans *= 10;
        Ans += s[i] - '0';
        Ans %= MOD;
    }
    cout << Ans << '\n';
}

int main () {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}