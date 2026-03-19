#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
2
5 2
5 1
*/

void solve() {
    LL p, q;
    cin >> p >> q;
    if (p * p <= 4 * q * q) {
        cout << 0 << ' ' << 0 << '\n';
        return;
    } else if (sqrtl(p * p - 4 * q * q) != (LL)sqrtl(p * p - 4 * q * q)) {
        cout << 0 << ' ' << 0 << '\n';
        return;
    }
    LL t = sqrtl(p * p - 4 * q * q);
    LL g = __gcd(p + t, 2 * q);
    cout << (p + t) / g << ' ' << (2 * q) / g << '\n';
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}