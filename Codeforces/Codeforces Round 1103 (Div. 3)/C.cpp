#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL a, b, x, cnt = 0;
    cin >> a >> b >> x;
    if (a > b) swap(a, b);
    LL ans = b - a;
    while (a != b) {
        if (a > b) swap(a, b);
        ans = min(ans, b - a + cnt);
        b /= x;
        cnt ++;
    }
    ans = min(ans, cnt);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}