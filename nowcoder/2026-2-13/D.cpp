#include <bits/stdc++.h>

#define double long double

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

struct node 
{
    LL x, y, w;
    bool operator < (const node&T) const {
        return w > T.w;
    }
};

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    LL n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<LL>> Mp(n + 1, vector<LL> (m + 1, 0));
    priority_queue<node> q;
    vector<vector<LL>> dis(n + 1, vector<LL> (m + 1, inf));
    vector<vector<bool>> vis(n + 1, vector<bool> (m + 1, 0));
    for (int i = 1;i <= a;i ++) {
        int x, y;
        cin >> x >> y;
        q.push({x, y, 0});
        dis[x][y] = 0;
    }
    for (int i = 1;i <= b;i ++) {
        int x, y, d;
        cin >> x >> y >> d;
        Mp[x][y] = d;
    }
    auto valid = [&](int x, int y) -> bool {
        return (1 <= x && x <= n && 1 <= y && y <= m);
    };
    while (siz(q)) {
        auto [x, y, d] = q.top();
        q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (int k = 0;k < 4;k ++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (!valid(nx, ny) || vis[nx][ny]) continue;
            if (max(dis[x][y] + 1, Mp[nx][ny]) < dis[nx][ny]) {
                dis[nx][ny] = max(dis[x][y] + 1, Mp[nx][ny]);
                q.push({nx, ny, dis[nx][ny]});
            }
        }
    }
    LL Mx = 0;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            // cout << dis[i][j] << ' ';
            Mx = max(Mx, dis[i][j]);
        }
    }
    cout << Mx << '\n';
}

int main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}