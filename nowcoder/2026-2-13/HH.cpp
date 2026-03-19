#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    vector<vector<bitset<2048>>> dp(n + 1, vector<bitset<2048>>(2));
    dp[0][0][0] = dp[0][1][0] = 1;
    for (int i = 1;i <= n;i ++) {
        for (int j = 0;j < 2048;j ++) {
            if (dp[i - 1][0][j] || dp[i - 1][1][j]) {
                dp[i][0][max(0, j - a[i])] = 1;
                dp[i][1][j ^ b[i]] = 1;
            }
        }
    }
    int Mx = 0;
    for (int j = 0;j < 2048;j ++) {
        if (dp[n][0][j] || dp[n][1][j]) Mx = j;
    }
    cout << Mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}