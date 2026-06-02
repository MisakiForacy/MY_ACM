#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    LL n, a, b;
    cin >> n >> a >> b;
    if (a * 3 <= b) {
        cout << a * n << '\n';
    } else {
        LL ans = n / 3 * b;
        cout << ans + min(n % 3 * a, b) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}