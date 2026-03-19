#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL x = 1;
    for (int i = 1;i <= 200;i ++) {
        x *= 3;
        cout << x << '\n';
    }
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}