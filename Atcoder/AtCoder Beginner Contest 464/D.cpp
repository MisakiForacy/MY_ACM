#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const LL inf = 1e15;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<LL> x(n + 1, 0), y(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> x[i];
    for (int i = 1;i < n;i ++) cin >> y[i];
    vector<vector<LL>> dp(n + 1, vector<LL> (2, -inf));
    dp[0][1] = 0;
    for (int i = 1;i <= n;i ++) {
        if (s[i] == 'S') {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + y[i - 1]);
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]) - x[i];
        } else {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + y[i - 1]) - x[i];
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        }
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}