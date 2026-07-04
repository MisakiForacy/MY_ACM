#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    LL x, y, k;
    cin >> x >> y >> k;
    LL cnt = 0;
    LL mi = x, mx = x;
    int ok = 0;
    while (mi > y || mx < y) {
        if (mx < y) {
            mx = k * (mx + 1) - 1;
            mi = k * mi;
        } else if (mi > y) {
            mx /= k;
            mi /= k;
        }
        cnt ++;
        cout << mi << ' ' << mx << '\n';
        getchar();
    }
    cout << cnt << '\n';
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
