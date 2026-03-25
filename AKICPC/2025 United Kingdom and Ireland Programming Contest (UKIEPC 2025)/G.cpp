#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    LL n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    LL v1 = 0, v2 = 0;
    v1 = min(n, x) * a + (n - min(n, x)) * b;
    if (n <= x) {
        v2 = n * a;
    } else {
        v2 = x * a;
        n = n - x;
        LL t = n / (x + y);
        v2 += t * x * a;
        n -= t * (x + y);
        if (n > y) {
            v2 += max((n - y) * a, n * b);
        } else {
            v2 += n * b;
        }
    }
    // cout << v1 << ' ' << v2 << '\n';
    cout << max(v1, v2) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}