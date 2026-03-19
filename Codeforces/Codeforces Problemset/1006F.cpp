#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    LL n, m, K;
    cin >> n >> m >> K;
    vector<vector<LL>> a(n + 2, vector<LL> (m + 2, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cin >> a[i][j];
        }
    }
    if (n * m == 1) {
        cout << (a[1][1] == K) << '\n';
        return 0;
    }
    vector<vector<bool>> vis(n + 1, vector<bool> (m + 1, 0));
    vector<vector<map<LL, LL>>> dp(n + 1, vector<map<LL, LL>> (m + 1));
    int len = n + m - 1;
    int Lo = len / 2, Hi = len - Lo;
    queue<PII> s, f;
    s.push({1, 1}), f.push({n, m});
    dp[1][1][a[1][1]] = 1, dp[n][m][a[n][m]] = 1;
    vis[1][1] = vis[n][m] = 1;
    auto valid = [&](int x, int y) -> bool {
        if (1 <= x && x <= n && 1 <= y && y <= m) 
            return 1;
        return 0;
    };
    while (!s.empty()) {
        auto [x, y] = s.front();
        s.pop();
        if (x + y - 1 > Lo) continue;
        if (valid(x - 1, y)) for (auto [k, v] : dp[x - 1][y]) dp[x][y][k ^ a[x][y]] += v;
        if (valid(x, y - 1)) for (auto [k, v] : dp[x][y - 1]) dp[x][y][k ^ a[x][y]] += v;
        if (valid(x + 1, y)) if (!vis[x + 1][y] && x + y <= Lo) 
            s.push({x + 1, y}), vis[x + 1][y] = 1;
        if (valid(x, y + 1)) if (!vis[x][y + 1] && x + y <= Lo) 
            s.push({x, y + 1}), vis[x][y + 1] = 1;
    }
    while (!f.empty()) {
        auto [x, y] = f.front();
        f.pop();
        if (n + m - x - y > Hi) continue;
        if (valid(x + 1, y)) for (auto [k, v] : dp[x + 1][y]) dp[x][y][k ^ a[x][y]] += v;
        if (valid(x, y + 1)) for (auto [k, v] : dp[x][y + 1]) dp[x][y][k ^ a[x][y]] += v;
        if (valid(x - 1, y)) if (!vis[x - 1][y] && n + m - x - y + 1 <= Hi) 
            f.push({x - 1, y}), vis[x - 1][y] = 1;
        if (valid(x, y - 1)) if (!vis[x][y - 1] && n + m - x - y + 1 <= Hi) 
            f.push({x, y - 1}), vis[x][y - 1] = 1;
    }
    LL Ans = 0;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            if (i + j - 1 == Lo) {
                for (auto [k, v] : dp[i][j]) {
                    if (valid(i + 1, j)) {
                        Ans += v * dp[i + 1][j][k ^ K];
                    }
                    if (valid(i, j + 1)) {
                        Ans += v * dp[i][j + 1][k ^ K];
                    }
                }
            }
        }
    }
    cout << Ans << '\n';
}