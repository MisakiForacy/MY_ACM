#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const LL inf = 1e9;

void solve() {
    int n, m, sx, sy;
    cin >> m >> n;
    vector<vector<int>> a(m + 1, vector<int> (n + 1, 0));
    vector<vector<int>> d(m + 1, vector<int> (n + 1, inf));
    vector<vector<int>> vis(m + 1, vector<int> (n + 1, 0));
    for (int i = 1;i <= m;i ++) {
        for (int j = 1;j <= n;j ++) {
            cin >> a[i][j];
            a[i][j] -= 1;
            if (a[i][j] == 1) {
                sx = i, sy = j;
            }
        }
    }
    queue<PLL> q;
    q.push({sx, sy});
    d[sx][sy] = 0;
    while (siz(q)) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0;k < 4;k ++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            if (vis[nx][ny]) continue;
            if (a[nx][ny] == -1) continue;
            d[nx][ny] = d[x][y] + 1;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    // for (int i = 1;i <= m;i ++) {
    //     for (int j = 1;j <= n;j ++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // } 
    int qq;
    cin >> qq;
    vector<PLL> p(qq + 1);
    map<int, vector<int>> mp;
    for (int i = 1;i <= qq;i ++) {
        cin >> p[i].second >> p[i].first;
        mp[d[p[i].first][p[i].second]].push_back(i);
    }
    for (auto [k, v] : mp) {
        if (siz(v) == 1 && k != inf) {
            cout << v[0] << ' ' << d[p[v[0]].first][p[v[0]].second] << '\n';
            return;
        }
    }
    cout << "No winner.\n";
}

int main() {
    // cout << fixed << setprecision(2);
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}