#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

#define LOG 20

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

void solve () {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> d;
    for (int i = 1;i <= k;i ++) {
        int r, c;
        cin >> r >> c;
        d.push_back({r, c});
    }
    // int M = min(m - 2, 10);
    int M = k;
    for (int T = 0;T < 1LL << M;T ++) {
        vector<vector<LL>> dp(n + 1, vector<LL> (m + 1, inf));
        for (int j = 0;j < M;j ++) {
            int r = d[j].x, c = d[j].y;
            if (T >> j & 1)
                for (int x = 1;x <= r;x ++) dp[x][c] = -1;
            else
                for (int x = r;x <= n;x ++) dp[x][c] = -1;
        }
        queue<pair<int, int>> q; 
        for (int i = 1;i <= n;i ++) q.push({i, 1}), dp[i][1] = 0;
        while (siz(q)) {
            auto [x, y] = q.front();
            q.pop();
            if (x - 1  > 0 && dp[x - 1][y] != -1) {
                if (dp[x - 1][y] > dp[x][y] + 1) {
                    dp[x - 1][y] = dp[x][y] + 1;
                    q.push({x - 1, y});
                }
            }
            if (x + 1 <= n && dp[x + 1][y] != -1) {
                if (dp[x + 1][y] > dp[x][y] + 1) {
                    dp[x + 1][y] = dp[x][y] + 1;
                    q.push({x + 1, y});
                }
            }
            if (y + 1 <= m && dp[x][y + 1] != -1) {
                if (dp[x][y + 1] > dp[x][y] + 1) {
                    dp[x][y + 1] = dp[x][y] + 1;
                    q.push({x, y + 1});
                }
            }
        }
        LL Min = inf;
        for (int i = 1;i <= n;i ++) Min = min(Min, dp[i][m]);
        cout << (Min == inf ? -1 : Min) << ' ';
    }
    cout << '\n';
}

/*
3
3 6
2
3 4
2 5
3 4
1
1 2
3 6
2
3 2
1 5
*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}