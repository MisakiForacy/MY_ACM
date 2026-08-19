#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

#define x first 

#define y second 

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

const int N = 24;

const LL inf = 1e15;

void solve() {
    cout << fixed << setprecision(16);
    LL m, r, c;
    cin >> m >> r >> c;
    // if (m + r < c) {
    LL k = (c + m + r - 1) / (m + r);
    // while (k * (m + r) < c) k ++;
    cout << k << '\n';
    if (k * (m + r) - r >= c) {
        LL p = k * m;
        LL t = k * (m + r) - r;
        cout << 1.0 * p / t << '\n';
    } else {
        LL p = (k + 1) * m;
        LL t = k * (m + r) + m;
        cout << p << ' ' << t << '\n';
        LL v = c - (k * (m + r) - r);
        long double ans1 = 1.0 * p / t;
        t = v + k * (m + r) - r + m;
        cout << p << ' ' << t << '\n';
        long double ans2 = 1.0 * p / t;
        cout << max(ans1, ans2) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}


