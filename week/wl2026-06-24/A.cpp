#include <bits/stdc++.h>

using namespace std;

using LL = long long;

LL mul(LL a, LL b, LL m) {
    LL r = a * b - m * LL(1.L / m * a * b);
    return r - m * (r >= m) + m * (r < 0);
}

LL pow(LL a, LL b, LL m) {
    LL res = 1 % m;
    for (;b;b >>= 1, a = mul(a, a, m)) {
        if (b & 1) res = mul(res, a, m);
    }
    return res;
}

bool isprime(LL n) {
    if (n < 2 || n % 6 % 4 != 1) {
        return (n | 1) == 3;
    }
    LL s = __builtin_ctzll(n - 1), d = n >> s;
    for (LL a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        LL p = pow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i --) {
            p = mul(p, p, n);
        }
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}

bitset<10000001> s;

void init() {
    s.reset();
    s[1] = 1;
    for (LL i = 2;i <= 10000000;i ++) {
        if (!s[i]) {
            for (LL j = i * i;j <= 10000000;j += i) {
                s[j] = 1;
            }
        }
    }
}

void solve() {
    int ans = 0;
    LL l, r;
    cin >> l >> r;
    for (LL a = 1;a * a <= r;a ++) {
        for (LL b = a + 1;a * a + b * b <= r;b += 2) {
            if (a * a + b * b < l) continue;
            if (a * a + b * b <= 10000000) {
                if (s[a * a + b * b]) continue;
            } else {
                if (!isprime(a * a + b * b)) continue;
            }
            if (l <= a * a + b * b) ans ++;
        }
    }
    cout << ans + (l <= 2) << '\n';
}


// 10
// 101
// 1101
// 10001
// 11101
// 100101

// 1 * 1 + 2 * 2
// 1 * 1 + 4 * 4
// 1 * 1 + 6 * 6

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}