#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    LL n, x, y, k;
    cin >> n >> x >> y >> k;
    int l = max(abs(x - y), n - abs(x - y));
    int s = min(abs(x - y), n - abs(x - y));
    if (n <= 3) {
        cout << 1 << '\n';
    } else {
        cout << k + s << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}