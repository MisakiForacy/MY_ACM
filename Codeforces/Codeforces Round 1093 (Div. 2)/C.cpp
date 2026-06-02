#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL p, q;
    cin >> p >> q;
    LL s = p + 2 * q;
    for (LL n = 1;n * n <= s;n ++) {
        if (s - n <= 0) break;
        if ((s - n) % (2 * n + 1)) continue;
        LL m = (s - n) / (2 * n + 1);
        if (m <= 0) continue;
        LL xx = m * (n + 1);
        LL yy = n * (m + 1);
        if (yy < q || xx < q) continue;
        if (yy + xx - 2 * q != p) continue;
        cout << n << ' ' << m << '\n';
        return;
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}