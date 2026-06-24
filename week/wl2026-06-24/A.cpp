#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int ans = 0;
    LL l, r;
    cin >> l >> r;
    for (LL a = 1;a * a <= r;a ++) {
        for (LL b = 1;a * a + b * b <= r;b ++) {
            if (a * a + b * b == r) {
                if (l <= a * a + b * b && a * a + b * b <= r) ans ++;
            }
        }
    }
    cout << ans << '\n';
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
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}