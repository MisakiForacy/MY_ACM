#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    LL x, d = 0;
    cin >> x;
    for (int i = 0;i <= 63;i ++) {
        if (x >> i & 1) d = max(d, LL(i));
    }
    d += 1;
    for (int i = 0;i <= 64;i ++) {
        if ((1LL << i) >= d) {
            cout << (1LL << i);
            if (i) cout << " bits\n";
            else   cout << " bit\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}