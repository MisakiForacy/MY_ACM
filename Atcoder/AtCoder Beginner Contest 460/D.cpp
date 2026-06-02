#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct node 
{
    int x, y, d;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n + 2, vector<int> (m + 2, 0));
    vector<vector<int>> vis(n + 2, vector<int> (m + 2, 1));
    vector<vector<int>> vis1(n + 2, vector<int> (m + 2, 1));
    queue<node> q, q1;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            char c;
            cin >> c;
            mp[i][j] = c == '#';
            if (mp[i][j]) 
                q.push({i, j, 0}), vis[i][j] = 1;
            else 
                vis[i][j] = 0;
            vis1[i][j] = 0;
        }
    }
    int mx = 1;
    while (siz(q)) {
        auto [x, y, d] = q.front();
        q.pop();
        mp[x][y] = 0;
        for (int k = 0;k < 8;k ++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (!vis[nx][ny]) {
                mp[nx][ny] = 1;
                vis1[nx][ny] = 1;
                vis[nx][ny] = 1;
                q1.push({nx, ny, 1});
            }
        }
    }
    while (siz(q1)) {
        auto [x, y, d] = q1.front();
        q1.pop();
        mx = max(mx, d);
        if (d & 1) mp[x][y] = 1;
        for (int k = 0;k < 8;k ++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (!vis1[nx][ny]) {
                vis1[nx][ny] = 1;
                q1.push({nx, ny, d + 1});
            }
        }
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            if (mx & 1) {
                cout << (mp[i][j] ? '#' : '.');
            } else {
                cout << (mp[i][j] ? '.' : '#');
            }
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
