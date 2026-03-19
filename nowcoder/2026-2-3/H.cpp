#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;
const LL MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 2, 0);
    vector<vector<int>> pre(32, vector<int> (n + 2, 0));
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<map<LL, LL>> dp(n + 1);
    dp[1][a[1]] = 1;
    for (int i = 2;i <= n;i ++) {
        for (auto [k, v] : dp[i - 1]) {
            if (k + a[i] == (k | a[i])) {
                dp[i][k | a[i]] += v;
                dp[i][k | a[i]] %= MOD;
            }
            dp[i][a[i]] += v;
            dp[i][a[i]] %= MOD;
        }
    }
    LL ans = 0;
    for (auto [k, v] : dp[n]) {
        ans += v;
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}