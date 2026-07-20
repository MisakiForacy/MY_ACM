#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n + 1, 0), b(n, 0), c(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i < n;i ++) cin >> b[i];
    int l = 0, r = m;
    auto check = [&](int x) -> bool {
        c[1] = x;
        LL sum1 = c[1];
        for (int i = 2;i < n;i ++) {
            c[i] = (b[i - 1] - (c[i - 1] + a[i - 1] + a[i]) % m);
            if (c[i] < 0) c[i] += m;
            sum1 += c[i];
        }
        c[1] = x + 1;
        LL sum2 = c[1];
        for (int i = 2;i <= n;i ++) {
            c[i] = (b[i - 1] - (c[i - 1] + a[i - 1] + a[i]) % m);
            if (c[i] < 0) c[i] += m;
            sum2 += c[i];
        }
        return sum1 >= sum2;
    };
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    // cout << l << '\n';
    // for (l = 0;l < m;l ++) {
        c[1] = l;
        LL ans = c[1];
        for (int i = 2;i <= n;i ++) {
            c[i] = (b[i - 1] - (c[i - 1] + a[i - 1] + a[i]) % m);
            if (c[i] < 0) c[i] += m;
            ans += c[i];
        }
        // for (int i = 1;i <= n;i ++) {
        //     cout << c[i] << ' ';
        // }
        // cout << '\n';
        cout << ans << '\n';
    // }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}