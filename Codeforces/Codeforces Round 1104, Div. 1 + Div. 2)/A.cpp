#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    LL ans = 0, mi = 1e15;
    for (int i = 1;i <= n;i ++) {
        LL x;
        cin >> x;
        mi = min(x, mi);
        ans += min(x, mi);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}