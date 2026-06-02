#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int use = 1;
    LL ans = a[1] % mod;
    for (int i = 2;i <= n;i ++) {
        if (a[i] - use <= 0) {
            cout << 0 << '\n';
            return;
        }
        ans *= a[i] - use;
        ans %= mod;
        use ++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}