#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    LL n, m, d;
    cin >> n >> m >> d;
    int k = d / m + 1;
    cout << n / k + (n % k ? 1 : 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}