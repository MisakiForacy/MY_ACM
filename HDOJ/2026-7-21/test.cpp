#include <bits/stdc++.h>

#define x first 
#define y second

using namespace std;
using LL = long long;

const int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};

const int N = 405;

int a[N][N], vis[N][N];

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    memset(a, -1, sizeof(a));
    queue<pair<int, int>> q;
    q.push({x, y});
    a[x][y] = 0;
    vis[x][y] = 1;
    while (q.size()) {
        pair<int, int> top = q.front();
        int x = top.first;
        int y = top.second;
        q.pop();
        for (int k = 0;k < 8;k ++) {
            int nx = x + dx[k], ny = y + dy[k];
            if ((1 <= nx && nx <= n && 1 <= ny && ny <= m) && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                a[nx][ny] = a[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}