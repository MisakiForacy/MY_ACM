#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    LL x1, y1, x2, y2, r1, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    LL mx = r1 + r2;
    LL mi = abs(r1 - r2);
    mx = mx * mx;
    mi = mi * mi;
    LL d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    cout << (mi <= d && d <= mx ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
