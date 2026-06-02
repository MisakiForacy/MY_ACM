#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int x = n;
    LL ans = 0;
    while (x > 0) {
        ans += (1 + x) * x / 2;
        x --;
    }
    x = n - 1;
    while (x > 0) {
        ans += (1 + x) * x / 2;
        x -= 2;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}