#include <bits/stdc++.h>

#define int long long

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
 
using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
  
struct node
{
    LL x, y, d;
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n + 1, vector<int> (m + 1, 0));
    vector<vector<int>> p(n + 1, vector<int> (m + 1, 0));
    vector<vector<int>> vis(n + 1, vector<int> (m + 1, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cin >> a[i][j];
        }
    }
    // cout << '\n';
    auto valid = [&](int x, int y) -> bool {
        return (1 <= x && x <= n && 1 <= y && y <= m);
    };
    auto bfs = [&](int x, int y) -> LL {
        queue<node> q;
        q.push({x, y, 0});
        vis[x][y] = 1;
        LL S = 0;
        while (siz(q)) {
            auto [x, y, d] = q.front();
            q.pop();
            if (d > 2) break;
            if (d <= 2) S += a[x][y];
            for (int k = 0;k < 4;k ++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (!valid(nx, ny) || vis[nx][ny]) continue;
                q.push({nx, ny, d + 1});
                vis[nx][ny] = 1;
            }
        }
        return S;
    };
    auto get = [&](int x, int y) -> LL {
        LL S = bfs(x, y);
        for (int i = -3;i <= 3;i ++) {
            for (int j = -3;j <= 3;j ++) {
                int nx = x + i, ny = y + j;
                if (!valid(nx, ny)) continue;
                vis[nx][ny] = 0;
            }
        }
        return S;
    };
    LL Mx = 0;
    LL sx = -1, sy = -1;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            p[i][j] = get(i, j);
            if (p[i][j] > Mx) {
                Mx = p[i][j];
                sx = i, sy = j;
            }
            // cout << p[i][j] << ' ';
        }
        // cout << '\n';
    }
    vector<vector<int>> V(n + 1, vector<int> (m + 1, 0));
    while (q --) {
        LL x, y, z;
        cin >> x >> y >> z;
        a[x][y] += z;
        queue<node> q;
        q.push({x, y, 0});
        V[x][y] = 0;
        while (siz(q)) {
            auto [x, y, d] = q.front();
            q.pop();
            if (d <= 2) {
                p[x][y] = get(x, y);
                if (p[x][y] > Mx) {
                    Mx = p[x][y];
                    sx = x, sy = y;
                }
            } else break;
            for (int k = 0;k < 4;k ++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (!valid(nx, ny) || V[nx][ny]) continue;
                q.push({nx, ny, d + 1});
                V[nx][ny] = 1;
            }
        }
        for (int i = -3;i <= 3;i ++) {
            for (int j = -3;j <= 3;j ++) {
                int nx = x + i, ny = y + j;
                if (!valid(nx, ny)) continue;
                V[nx][ny] = 0;
            }
        }
        // cout << Mx << '\n';
        cout << sx << ' ' << sy << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}