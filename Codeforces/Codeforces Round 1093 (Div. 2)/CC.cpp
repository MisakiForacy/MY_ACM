#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL p, q;
    cin >> p >> q;
    LL x = q, y = q;
    for (LL n = 1;n <= 10000;n ++) {
        for (LL m = 1;m <= 10000;m ++) {
            LL xx = m * (n + 1);
            LL yy = n * (m + 1);
            if (yy < y || xx < x) continue;
            if (xx + yy - x - y != p) continue;
            cout << n << ' ' << m << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}