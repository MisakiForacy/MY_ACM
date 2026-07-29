#include <bits/stdc++.h>

#define x first 
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(100010);
    dp[0] = 1;
    for (int i = 0;i < n;i ++) {
        int x;
        cin >> x;
        vector<int> ndp = dp;
        for (int j = 0;j <= 100000;j ++) {
            if (dp[j]) {
                ndp[j + x] = 1;
                ndp[abs(j - x)] = 1;
            }
        }
        dp = ndp;
    }
    int ans = 0;
    for (int i = 1;i <= 100000;i ++) ans += dp[i];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}