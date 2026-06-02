#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0), p(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1;i <= n;i ++) p[i] = p[i - 1] + a[i];
    int ans = 0;
    for (int i = 1;i <= n;i ++) {
        LL ave = p[i] / i;
        ans = max(ans, i - int(upper_bound(all(a), ave) - a.begin() - 1));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}