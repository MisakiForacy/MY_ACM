#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<int,int>;

void solve() {
    int n;
    cin >> n;
    vector<PII> p(n + 1);
    int dp[2][11];
    memset(dp, 0, sizeof dp);
    for (int i = 1;i <= n;i ++) {
        cin >> p[i].x >> p[i].y;
        if (p[i].x == 0) {
            for (int j = 1;j <= 10;j ++) {
                if (j == p[i].y) continue;
                dp[0][p[i].y] = max(dp[0][p[i].y], dp[1][j] + 1);
            }
        } else {
            for (int j = 1;j <= 10;j ++) {
                if (j == p[i].y) continue;
                dp[1][p[i].y] = max(dp[1][p[i].y], dp[0][j] + 1);
            }
        }
    }
    int Mx = 0;
    for (int i = 1;i <= 10;i ++) Mx = max({Mx, dp[0][i], dp[1][i]});
    cout << Mx << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}