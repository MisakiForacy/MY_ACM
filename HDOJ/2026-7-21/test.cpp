#include <bits/stdc++.h>

using namespace std;

using LL = long long;

int n;
int a[1205][1205];

const LL inf = 1e15;

const int dx1[] = {0, 1, 0, -1};
const int dy1[] = {1, 0, -1, 0};

const int dx2[] = {1, 1, -1, -1};
const int dy2[] = {1, -1, 1, -1};

LL bfs(int sx, int sy, int fx, int fy) {
    if (a[sx][sy] == -1) return inf;
    queue<pair<int, int>> q;
    int vis[n + 2][n + 2];
    LL dis[n + 2][n + 2];
    memset(vis, 0, sizeof vis);
    for (int i = 0;i <= n + 1;i ++) {
        for (int j = 0;j <= n + 1;j ++) {
            dis[i][j] = inf;
        }
    }
    q.push({sx, sy});
    vis[sx][sy] = 1;
    dis[sx][sy] = 0;
    while (q.size()) {
        pair<int, int> top = q.front();
        int x = top.first, y = top.second;
        q.pop();
        for (int k = 0;k < 4;k ++) {
            int nx = x + (a[x][y] <= 2 ? dx1[k] : dx2[k]);
            int ny = y + (a[x][y] <= 2 ? dy1[k] : dy2[k]);
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (vis[nx][ny] || a[nx][ny] == -1) continue;
            vis[nx][ny] = 1;
            dis[nx][ny] = dis[x][y] + (2 - a[x][y] % 2);
            q.push({nx, ny});
        }
    }
    return dis[fx][fy];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            char c;
            cin >> c;
            if (c == 'A') {
                a[i][j] = 1;
            } else if (c == 'B') {
                a[i][j] = 2;
            } else if (c == 'C') {
                a[i][j] = 3;
            } else {
                a[i][j] = -1;
            }
        }
    }
    LL ans = inf;
    ans = min(ans, bfs(1, 1, n, n));
    ans = min(ans, bfs(1, n, n, n));
    ans = min(ans, bfs(n, 1, n, n));
    if (ans == inf) {
        cout << "No answer\n";
    } else {
        cout << ans << '\n';
    }
}