#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;

using LL = long long;

const LL mod = 998244353;

void solve() {
    LL n, k;
    cin >> n >> k;
    int m = min(n, k);
    LL f[m + 1][k + 1];
    memset(f, 0, sizeof(f));
    // f[i][j] j
    for (int i = 1;i <= k;i ++) f[1][i] = 1;
    for (int i = 2;i <= m;i ++) {
        for (int j = 1; j <= k; ++j) {
            LL L = ((i - 1) * j + 1 + i - 1) / i, R = ((i - 1) * j + k) / i;
            for (int j1 = L; j1 <= R; ++j1)
                f[i][j1] = (f[i][j1] + f[i - 1][j]) % mod;
        }
    }
    LL ans = 0;
    for (int i = 1; i <= k; ++i) ans = (ans + f[m][i]) % mod;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}