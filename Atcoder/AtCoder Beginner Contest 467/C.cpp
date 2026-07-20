#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = n;
    vector<LL> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n - 1;i ++) cin >> b[i];
    for (int i = 0;i < 2;i ++) {
        int s = i, cnt = 0;
        for (int j = 1;j <= n;j ++) {
            cnt += a[j] != s;
            if (j + 1 <= n) s ^= b[j];
        }
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}