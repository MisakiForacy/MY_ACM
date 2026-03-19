#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    vector<double> p(n), c(n), dp(n + 1, 0);
    for (int i = 0;i < n;i ++) cin >> c[i] >> p[i];
    for (int i = n - 1;i >= 0;i --) {
        dp[i] = max(dp[i + 1], dp[i + 1] * (1.0 - p[i] / 100) + c[i]);
    }
    cout << dp[0] << '\n';
}

int main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}