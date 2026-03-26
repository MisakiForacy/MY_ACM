#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i], a[i] %= k;
    sort(a.begin() + 1, a.end());
    LL ans = k + 1;
    for (int i = 1;i <= n;i ++) {
        ans = min(ans, a.back() - a[i]);
        a.push_back(a[i] + k);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}