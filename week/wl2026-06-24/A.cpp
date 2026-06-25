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
    if (n % 5 == 0 || n % 2 == 0 || n % 3 == 0) return 0;
    if (n < 2 || n % 6 % 4 != 1) {
        return (n | 1) == 3;
    }
    LL s = __builtin_ctzll(n - 1), d = n >> s;
    for (LL a : {2, 7, 61}) {
        LL p = pow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i --) {
            p = mul(p, p, n);
        }
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}

void solve() {
    int ans = 0;
    LL l, r;
    cin >> l >> r;
    for (LL a = 1;a * a <= r;a ++) {
        for (LL b = a + 1;a * a + b * b <= r;b += 2) {
            if (a * a + b * b < l) continue;
            if (!isprime(a * a + b * b)) continue;
            if (l <= a * a + b * b) ans ++;
        }
    }
    cout << ans + (l <= 2 && r >= 2) << '\n';
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

// 2 * 2 + 3 * 3 == 4 + 9
// 2 * 2 + 5 * 5 == 29
// 2 * 2 + 7 * 7 == 53
// 2 * 2 + 

int main() {
    // init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}