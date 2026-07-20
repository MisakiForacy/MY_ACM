#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n + 1, 0), b(n, 0), c(n, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i < n;i ++) cin >> b[i];
    for (int i = 1;i < n;i ++) 
        c[i] = (b[i] - (a[i] + a[i + 1] + m) % m + m) % m;
    LL ans = 0;
    for (int i = 1;i < n;i ++) cout << c[i] << ' ';
    cout << '\n';
    for (int i = 1;i < n - 1;i ++) {
        if (c[i] > c[i + 1]) {
            ans += c[i];
            c[i + 1] = 0;
        } else {
            ans += c[i + 1];
            c[i + 1] = 0;
        }
        cout << ans << ' ';
    }
    ans += c[n - 1];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}