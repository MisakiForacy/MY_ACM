#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

#define LOG 30

void solve() {
    int n, q;
    cin >> n >> q;
    vector<LL> a(n + 1), d(n + 1, 0);
    vector<vector<LL>> fa(LOG + 1, vector<LL> (n + 1, 0));
    vector<vector<LL>> dp(LOG + 1, vector<LL> (n + 1, 0));
    for (int i = 1;i <= n;i ++) dp[0][i] = i;
    for (int i = 1;i <= n;i ++) cin >> a[i], fa[0][i] = a[i];
    for (int j = 1;j <= LOG;j ++) {
        for (int i = 1;i <= n;i ++) {
            fa[j][i] = fa[j - 1][fa[j - 1][i]];
            dp[j][i] = dp[j - 1][i] + dp[j - 1][fa[j - 1][i]];
        }
    }
    while (q --) {
        LL t, b;
        cin >> t >> b;
        LL Sm = 0, Cur = b;
        for (int j = 30;j >= 0;j --) {
            if ((1LL << j) > t) continue;
            t -= 1LL << j;
            Sm += dp[j][Cur];
            Cur = fa[j][Cur];
        }
        cout << Sm << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}