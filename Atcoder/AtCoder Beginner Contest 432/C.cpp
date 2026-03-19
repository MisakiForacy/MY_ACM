#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;


/*
6 8
1  2  3  4  5  6  7  8  9 10 11 12 13
8  8  8  8  8  8  8  8  8  8    => 80
8  8  8  8  8  8  8  6  6  6  6 => 80
8  8  8  8  8  8  8  6  6  6  6  6  6 => 92

*/


void solve () {
    LL n, x, y;
    cin >> n >> x >> y;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(all(a));
    LL ans = 0;
    LL lcm = x * y / __gcd(x, y);
    LL Cx = lcm / x, Cy = lcm / y;
    LL A = a[1];
    for (int i = 1;i <= n;i ++) {
        LL use = a[i] - a[max(1, i - 1)];
        if (use % (Cx - Cy)) {
            cout << -1 << '\n';
            return;
        }
        LL dat = use * x / (y - x);
        // cout << dat << ' ' << A << '\n';
        if (dat > A) {
            cout << -1 << '\n';
            return;
        }
        A -= dat;
        ans += A;
    }
    cout << ans << '\n';
}

int main () {
    solve ();
}