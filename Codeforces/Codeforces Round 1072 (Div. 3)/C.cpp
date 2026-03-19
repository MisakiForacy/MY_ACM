#include <bits/stdc++.h>

#define x first
#define y second

#define all(x) begin(x), end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    LL n, k;
    cin >> n >> k;
    int ans = -1;
    for (int i = 0;i <= 60;i ++) {
        LL p = 1LL << i;
        LL x = n / p, y = (n + p - 1) / p;
        if (k == x || k == y) {
            ans = i;
            break;
        }
        if (y == 0) break;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}