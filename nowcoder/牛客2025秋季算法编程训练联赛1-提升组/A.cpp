#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

const LL MOD = 1e9 + 7;

void solve() {
    LL n, m;
    cin >> n >> m;
    LL ans = 0;
    ans += (n - 1) * (n - 2) % MOD * (m - 2) % MOD * 2 % MOD;
    ans %= MOD;
    ans += (m - 1) * (m - 2) % MOD * (n - 2) % MOD * 2 % MOD;
    ans %= MOD;
    ans += (n - 2) * n % MOD * (m - 1) % MOD * 2 % MOD;
    ans %= MOD;
    ans += (m - 2) * m % MOD * (n - 1) % MOD * 2 % MOD;
    ans %= MOD;
    cout << ans << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}