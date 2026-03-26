#include <bits/stdc++.h>

#define x first 
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

// 8
// 7 2 -4 3 -1 2 -4 3

int main() {
    int n;
    cin >> n;
    int a[n + 1], f[n + 1];
    for (int i = 1;i <= n;i ++) cin >> a[i];
    int ans = a[1];
    f[1] = a[1];
    for (int i = 2;i <= n;i ++) {
        f[i] = max(a[i], f[i - 1] + a[i]);
        ans = max(ans, f[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    while (T --) solve();
}