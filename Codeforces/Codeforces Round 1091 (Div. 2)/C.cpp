#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    // 3411 4134 32 23
    LL n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << ((__gcd(n, a) == 1 && __gcd(m, b) == 1 && __gcd(n, m) <= 2) ? "YES\n" : "NO\n");
}

int main() {
    // 3411 4134 32 23
    // cout << 3411 * 4134 << '\n';
    // cout << __gcd(69387963,98793214) << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}