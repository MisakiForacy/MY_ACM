#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n;
    cin >> n;
    cout << (1LL << n) - 2 * n << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}