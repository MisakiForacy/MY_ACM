#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int A, B, P, Q;
    cin >> A >> B >> P >> Q;
    double p = P / 100.0;
    double q = Q / 100.0;
    vector<double> dp(A + 1);
    if (B == 1) {
        cout << max(A * (1 + p), A * (1 / (1 - q))) << '\n';
        return;
    }
    for (int i = B;i <= A;i ++) {
        dp[i] = 1 + p + dp[i - B];
        dp[i] = max(dp[i], q * dp[i - B + 1] + (1 - q) * dp[i - B] + 1);
    }
    cout << dp[A] << '\n';
}

int main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}

