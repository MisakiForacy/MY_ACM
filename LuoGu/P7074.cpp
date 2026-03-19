#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, -1};
const int dy[] = {1, 0, 0};

const LL inf = 1e18;

struct node
{
    LL u, w;
    bool operator < (const node&T) const {
        return T.w > w;
    };
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<LL>> a(n + 2, vector<LL> (m + 2, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cin >> a[i][j];
        }
    }
    LL dp[n + 2][m + 2][2];
    // dp[i][j][0] 向下，dp[i][j][1] 向上
    memset(dp, -0x3f, sizeof dp);
    dp[0][1][0] = dp[0][1][1] = dp[n + 1][1][0] = dp[n + 1][1][0] = 0;
    for (int j = 1;j <= m;j ++) {
        for (int i = 1;i <= n;i ++) {
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + a[i][j]);
            dp[i][j + 1][0] = max(dp[i][j][0], dp[i][j][1]) + a[i][j + 1];
            dp[i][j + 1][1] = max(dp[i][j][0], dp[i][j][1]) + a[i][j + 1];
        }
        for (int i = n;i >= 1;i --) {
            dp[i][j][1] = max(dp[i][j][1], dp[i + 1][j][1] + a[i][j]);
            dp[i][j + 1][0] = max(dp[i][j][0], dp[i][j][1]) + a[i][j + 1];
            dp[i][j + 1][1] = max(dp[i][j][0], dp[i][j][1]) + a[i][j + 1];
        }
    }
    cout << dp[n][m][0] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
