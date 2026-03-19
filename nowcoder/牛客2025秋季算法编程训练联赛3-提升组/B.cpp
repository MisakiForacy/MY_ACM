#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

map<pair<char, char>, int> mp;

void dfs (int n, char a, char b, char c) {
    if (n == 1) {
        mp[{a, c}] ++;
        // cout << a << "->" << c << '\n';
    } else {
        dfs (n - 1, a, c, b);
        mp[{a, c}] ++;
        // cout << a << "->" << c << '\n';
        dfs (n - 1, b, a, c);
    }
}

void solve() {
    int n;
    cin >> n;
    // dfs(n, 'A', 'B', 'C');
    LL sum = 0;
    vector<LL> dp(7, 0);
    dp[2] = 1;
    for (int i = 2;i <= n;i ++) {
        vector<LL> ndp(7, 0);
        ndp[1] = dp[2] + dp[3];
        ndp[2] = dp[1] + dp[4] + 1;
        ndp[3] = dp[1] + dp[5];
        ndp[4] = dp[2] + dp[3];
        ndp[5] = dp[3] + dp[6];
        ndp[6] = dp[1] + dp[5];
        dp = ndp;
    }
    int cnt = 0;
    for (char x = 'A';x <= 'C';x ++) {
        for (char y = 'A';y <= 'C';y ++) {
            if (x == y) continue;
            cout << x << "->" << y << ":" << dp[++ cnt] << '\n';
            sum += dp[cnt];
        }
    }
    cout << "SUM:" << sum << '\n';
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}