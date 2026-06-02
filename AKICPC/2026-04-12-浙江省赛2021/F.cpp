#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    LL n, m;
    cin >> n >> m;
    if (m % n == 0) {
        cout << 0 << '\n';
        return;
    }
    LL ans = inf;
    LL lim = (LL)(sqrt((long double)m)) + 1;
    // enumerate small possible final robot counts n'
    for (LL n2 = 1; n2 <= min(n, lim); ++n2) {
        LL rem = m % n2;
        LL add = (rem == 0 ? 0 : (n2 - rem));
        ans = min(ans, (n - n2) + add);
    }
    // enumerate small possible bars-per-robot k
    for (LL k = 1; k <= lim; ++k) {
        LL n2 = (m + k - 1) / k; // ceil(m/k)
        if (n2 <= 0 || n2 > n) continue;
        ans = min(ans, (n - n2) + (n2 * k - m));
    }
    // in case destroying down to m (when n>m) is best
    if (n > m) ans = min(ans, n - m);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}