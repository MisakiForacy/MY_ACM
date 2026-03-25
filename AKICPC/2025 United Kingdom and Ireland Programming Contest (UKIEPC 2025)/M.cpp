#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL mx = 0;
    for (int i = 2;i <= n;i ++) {
        mx = max(mx, a[i] - a[i - 1]);
    }
    LL mi = 1e15;
    for (int i = 2;i < n;i ++) {
        mi = min(mi, a[i + 1] - a[i - 1]);
    }
    cout << max(mi, mx) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}