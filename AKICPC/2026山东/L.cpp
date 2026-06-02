#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e18;

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

LL rho(LL n) {
    if (!(n & 1)) return 2;
    LL x = 0, y = 0, prod = 1;
    auto f = [&](LL x) -> LL {
        return mul(x, x, n) + 5;
    };
    for (int t = 30, z = 0;t % 64 || gcd(prod, n) == 1;t ++) {
        if (x == y) x = ++ z, y = f(x);
        if (LL q = mul(prod, x + n - y, n)) prod = q;
        x = f(x), y = f(f(y));
    }
    return gcd(prod, n);
}

vector<LL> fact(LL x) {
    vector<LL> res;
    auto f = [&](auto f, LL x) -> void {
        if (x == 1) return;
        if (isprime(x)) return res.push_back(x);
        LL y = rho(x);
        f(f, y), f(f, x / y);
    };
    f(f, x), sort(res.begin(), res.end());
    return res;
}

void solve() {
    LL a, b, q, f = 0;
    cin >> a >> b >> q;
    if (a > b) swap(a, b), f = 1;
    LL d = b - a;
    vector<LL> pre, A, B;
    pre.push_back(0), A.push_back(a), B.push_back(b);
    while (d > 1) {
        vector<LL> P = fact(d);
        LL Mi = inf;
        for (LL p : P) {
            Mi = min(Mi, p - a % p);
        }
        pre.push_back(pre.back() + Mi);
        a += Mi, b += Mi;
        LL g = __gcd(a, b);
        a /= g, b /= g;
        A.push_back(a), B.push_back(b);
        d = b - a;
    }
    while (q --) {
        LL aa, bb, val;
        cin >> val;
        if (a == b) {
            cout << 1 << ' ' << 1 << '\n';
            continue;
        }
        int pos = upper_bound(all(pre), val) - pre.begin() - 1;
        aa = A[pos] + val - pre[pos];
        bb = B[pos] + val - pre[pos];
        if (f) {
            cout << bb << ' ' << aa << '\n';
        } else {
            cout << aa << ' ' << bb << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}