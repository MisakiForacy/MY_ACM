#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL x, y;
    cin >> x >> y;
    if (y > x) {
        cout << 2 << '\n';
    } else if (1 < y && y < x - 1) {
        cout << 3 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}