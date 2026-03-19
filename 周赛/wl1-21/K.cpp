#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char> (m + 1));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cin >> a[i][j];
        }
    }
    auto vaild = [&](int x, int y) -> int {
        return ((1 <= x && x <= n) && (1 <= y && y <= m));
    };
    int ok = 0;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            vector<vector<int>> vis(n + 1, vector<int> (m + 1, 0));
            auto dfs = [&](auto dfs, int x, int y, int fx, int fy) -> void {
                vis[x][y] = 1;
                for (int k = 0;k < 4;k ++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (!vaild(nx, ny)) continue;
                    if (a[nx][ny] != a[x][y]) continue;
                    if (nx == fx && ny == fy) continue;
                    if (vis[nx][ny]) {
                        ok = 1;
                        return;
                    }
                    dfs(dfs, nx, ny, x, y);
                }
            };
            dfs(dfs, i, j, 0, 0);
            if (ok) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
