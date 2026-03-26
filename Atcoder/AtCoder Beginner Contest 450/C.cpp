#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 2, vector<int> (m + 2, 1));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            char c;
            cin >> c;
            a[i][j] = (c == '#');
        }
    }
    int ok, ans = 0;
    auto dfs = [&](auto dfs, int x, int y) -> void {
        a[x][y] = 1;
        if (x == 1 || x == n || y == 1 || y == m) ok = 0;
        for (int k = 0;k < 4;k ++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (a[nx][ny]) continue;
            dfs(dfs, nx, ny);
        }
    };
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            if (!a[i][j]) {
                ok = 1;
                dfs(dfs, i, j);
                ans += ok;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}