#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Mp (n + 2, vector<int> (m + 2, 0));
    vector<vector<int>> vis(n + 2, vector<int> (m + 2, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            char c; cin >> c;
            Mp[i][j] = (c == '*');
        }
    }
    int ok = 1, Tmp = 0;
    auto check = [&](int x, int y) -> int {
        LL Sm = 0;
        for (int i = -1;i <= 1;i ++) {
            for (int j = -1;j <= 1;j ++) {
                Sm += Mp[x + i][y + j];
            }
        }
        return (Sm == 3);
    };
    auto dfs = [&](auto dfs, int x, int y) -> void {
        ok = min(ok, check(x, y));
        vis[x][y] = 1;
        Tmp += 1;
        for (int k = 0;k < 4;k ++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (!vis[nx][ny] && Mp[nx][ny]) 
                dfs(dfs, nx, ny);
        }
    };
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            if (Mp[i][j] && !vis[i][j]) {
                Tmp = 0;
                dfs(dfs, i, j);
                ok = min(ok, int(Tmp == 3));
            }
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}