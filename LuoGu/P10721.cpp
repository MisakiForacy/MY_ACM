#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, m;
    cin >> n;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    cin >> m;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> pre(m + 2, 0);
    for (int i = 1;i <= m - 2;i ++) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
            pre[i] = pre[max(0, i - 3)] + 1;
        }
    }
    vector<LL> dp(m + 2, 0);
    for (int i = 1;i <= m;i ++) {
        dp[i] = dp[i - 1];
        if (pre[i]) {
            for (int j = 1;j <= min(pre[i], n);j ++) {
                dp[i] = max(dp[i], dp[max(0, i - j * 3)] + a[j]);
            }
        }
    }
    cout << dp[m] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}