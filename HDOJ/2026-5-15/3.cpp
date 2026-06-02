#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    LL n, x, ans = 0;
    cin >> n >> x;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) {
        ans += a[i];
        ans -= x;
        ans = max(ans, 0LL);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}