#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    LL lst = 0, ans = 0;
    for (int i = 1;i <= n;i ++) {
        LL sum = 0, x;
        for (int j = 0;j < m;j ++) {
            cin >> x;
            sum += x;
        }
        if (sum < lst) ans ++;
        lst = sum;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}