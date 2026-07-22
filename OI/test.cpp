#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 2, vector<int> (m + 2, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    }
    vector<vector<int>> vis(n + 2, vector<int> (m + 2, 0));
    int cnt = 0;
    auto dfs = [&](auto dfs, int x, int y) -> void {
        vis[x][y] = 1;
        for (int k = 0;k < 4;k ++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (!vis[nx][ny] && a[nx][ny]) {
                dfs(dfs, nx, ny);
            }
        }
    };
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            if (a[i][j] && !vis[i][j]) {
                dfs(dfs, i, j);
                cnt ++;
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
