#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL inf = 1e18;

void solve() {
    LL n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (n == 1) {
        if (m % 6 == 0) {
            cout << m << '\n';
        } else if (m % 6 == 5) {
            cout << m / 6 * 6 + 4 << '\n';
        } else if (m % 6 == 4) {
            cout << m / 6 * 6 + 2 << '\n';
        } else {
            cout << m / 6 * 6 << '\n';
        }
    } else if (n == 2) {
        if (m == 2) {
            cout << 0 << '\n';
        } else if (m == 3) {
            cout << 4 << '\n';
        } else if (m == 7) {
            cout << 12 << '\n';
        } else {
            cout << n * m << '\n';
        }
    } else {
        cout << n * m - n * m % 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}