#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<LL>> a(n + 1, vector<LL> (m + 1, 0));
    vector<vector<int>> vis(n + 1, vector<int> (m + 1, -1));
    map<int, vector<pair<int, int>>> mp;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cin >> a[i][j];
            mp[a[i][j]].push_back({i, j});
        }
    }    
    vector<int> pass(5, 0);
    auto dfs = [&](auto dfs, int x, int y, int t) -> void {
        vis[x][y] = t;
        if (x == 1) pass[1] = 1;
        if (x == n) pass[3] = 1;
        if (y == 1) pass[4] = 1;
        if (y == m) pass[2] = 1;
        for (int k = 0;k < 8;k ++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (!(1 <= nx && nx <= n && 1 <= ny && ny <= m)) continue;
            if (vis[nx][ny] == t) continue;
            if (a[nx][ny] != t) continue;
            dfs(dfs, nx, ny, t);
        }
    };
    auto check = [&](LL t) -> int {
        if (!mp.count(t)) return 1;
        for (auto [x, y] : mp[t]) {
            if (vis[x][y] == t) continue;
            for (int i = 1;i <= 4;i ++) pass[i] = 0;
            dfs(dfs, x, y, t);
            if (pass[1] && pass[3]) return 0;
            if (pass[4] && pass[2]) return 0;
            if (pass[2] && pass[3]) return 0;
            if (pass[1] && pass[4]) return 0;
        }
        return 1;
    };
    for (int t = 0;t < 5000;t ++) {
        if (check(t)) {
            cout << t << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}