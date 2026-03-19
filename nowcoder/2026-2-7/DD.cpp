#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<PLL>> use;
    vector<vector<int>> Mp(n + 1, vector<int> (m + 1));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            char c; cin >> c;
            Mp[i][j] = c - '0';
            if (c == '1') use[1].push_back({i, j});
            if (c == '2') use[2].push_back({i, j});
        }
    }
    /*
        先求出1 - 1的最短路径，然后再查询是否存在2 - 2
        先求出2 - 2 ...         再查询是否存在1 - 1
    */
    auto vaild = [&](int x, int y) -> bool {
        return (1 <= x && x <= n && 1 <= y && y <= m);
    };
    auto dir = [&](int x, int y, int fx, int fy) -> int {
        return abs(fx - x) + abs(fy - y);
    };
    auto check = [&](int from, int to) -> int {
        int sx = use[from][0].x, sy = use[from][0].y;
        int fx = use[from][1].x, fy = use[from][1].y;
        // cout << sx << ' ' << sy << ' ' << fx << ' ' << fy << '\n';
        vector<vector<int>> mp = Mp, vis(n + 1, vector<int> (m + 1, 0));
        queue<PLL> que;
        que.push({sx, sy});
        vis[sx][sy] = 1;
        int ok = 0;
        while (siz(que)) {
            // cout << "ok\n";
            auto [x, y] = que.front();
            que.pop();
            // cout << x << ' ' << y << '\n';
            LL Mi = inf, Tp = -1;
            for (int k = 0;k < 4;k ++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (!vaild(nx, ny) || vis[nx][ny] || (mp[nx][ny] && mp[nx][ny] != from)) continue;
                if (dir(nx, ny, fx, fy) < Mi) {
                    Mi = dir(nx, ny, fx, fy);
                    Tp = k;
                }
            }
            if (Tp == -1) break;
            int nx = x + dx[Tp], ny = y + dy[Tp];
            if (dir(nx, ny, fx, fy) == 0) {
                ok = 1;
                break;
            }
            mp[nx][ny] = from;
            vis[nx][ny] = 1;
            que.push({nx, ny});
        }
        if (!ok) return 0;
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= m;j ++) {
                vis[i][j] = 0;
            }
        }
        sx = use[to][0].x, sy = use[to][0].y;
        fx = use[to][1].x, fy = use[to][1].y;
        // cout << sx << ' ' << sy << ' ' << fx << ' ' << fy << '\n';
        vector<vector<LL>> dis(n + 1, vector<LL> (m + 1, inf));
        while (siz(que)) que.pop();
        que.push({sx, sy});
        dis[sx][sy] = 0, vis[sx][sy] = 1;
        while (siz(que)) {
            auto [x, y] = que.front();
            que.pop();
            if (x == fx && y == fy) return 1;
            for (int k = 0;k < 4;k ++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (!vaild(nx, ny) || (mp[nx][ny] && mp[nx][ny] != to) || vis[nx][ny]) continue;
                dis[nx][ny] = dis[x][y] + 1;
                vis[nx][ny] = 1;
                que.push({nx, ny});
            }
        }   
        return 0;
    };
    // cout << check(1, 2) << '\n';
    // cout << check(2, 1) << '\n';
    // cout << check(1, 2) << ' ' << check(2, 1) << '\n';
    if (!check(1, 2) && !check(2, 1)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}

/*
3
2 2
12
21
2 2
11
22
3 3
010
212
000
*/

/*
0102
0000
0000
0201
*/