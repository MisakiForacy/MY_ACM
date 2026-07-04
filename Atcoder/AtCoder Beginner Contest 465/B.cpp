#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    LL x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;
    LL ans = 0;
    for (int i = a;i < b;i ++) {
        if (l <= i && i < r) ans += x;
        else                  ans += y;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
