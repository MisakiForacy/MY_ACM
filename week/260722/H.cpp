#include <bits/stdc++.h>

#define x first 
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1), f(n + 1, 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j < i;j ++) {
            if (a[j] + 1 == a[i]) {
                f[i] = max(f[i], f[j] + 1);
                ans = max(ans, f[i]);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}