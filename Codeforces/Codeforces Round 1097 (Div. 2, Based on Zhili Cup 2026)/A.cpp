#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = n - 1;i >= 1;i --) a[i] = max(a[i], a[i] + a[i + 1]);
    for (int i = 1;i <= n;i ++) if (a[i] > 0) ans ++;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
