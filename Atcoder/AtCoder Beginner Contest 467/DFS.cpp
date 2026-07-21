#include <bits/stdc++.h>

#define x first 
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const int N = 105;

int a[N][N], vis[N][N], ans[N], idx[N][N];

void bfs(int x, int y, int t) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    idx[x][y] = t;
    ans[t] ++;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0;k < 4;k ++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (!vis[nx][ny] && !a[nx][ny]) {
                vis[nx][ny] = 1;
                idx[nx][ny] = t;
                ans[t] ++;
                q.push({nx, ny});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0;i <= n + 1;i ++) 
        for (int j = 0;j <= n + 1;j ++)
            a[i][j] = 1;
    for (int i = 1;i <= n;i ++) 
        for (int j = 1;j <= n;j ++) {
            char c;
            cin >> c;
            a[i][j] = c == '#';
        }
    int t = 0;
    for (int i = 1;i <= n;i ++) 
        for (int j = 1;j <= n;j ++) 
            if (!vis[i][j])
                bfs(i, j, ++ t);
    while (m --) {
        int x, y;
        cin >> x >> y;
        cout << ans[idx[x][y]] << '\n';
    } 
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}