#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

struct node
{
    int x, y, c, id;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 2, vector<int> (m + 2, 0)), aa, bb, vis;
    bb = a;
    vis = a;
    queue<node> q;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cin >> a[i][j];
        }
    }
    aa = a;
    int id = 0;
    auto valid = [&](int x, int y) -> int { return (1 <= x && x + 1 <= n && 1 <= y && y + 1 <= m); };
    auto check = [&](int x, int y) -> int {
        int ok = 1;
        if (!valid(x, y)) ok = 0;
        int mx = max({a[x][y], a[x + 1][y], a[x][y + 1], a[x + 1][y + 1]});
        if (mx == -1) ok = 0;
        if (!(a[x][y] == -1 || a[x][y] == mx)) ok = 0;
        if (!(a[x + 1][y] == -1 || a[x + 1][y] == mx)) ok = 0;
        if (!(a[x][y + 1] == -1 || a[x][y + 1] == mx)) ok = 0;
        if (!(a[x + 1][y + 1] == -1 || a[x + 1][y + 1] == mx)) ok = 0;
        return ok;
    };
    auto get = [&](int x, int y) -> int {
        return max({a[x][y], a[x + 1][y], a[x][y + 1], a[x + 1][y + 1]});
    };
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            if (check(i, j)) {
                q.push({i, j, a[i][j], ++ id});
            }
        }
    }
    vector<node> ans;
    while (siz(q)) {
        auto [x, y, c, idd] = q.front();
        q.pop();
        ans.push_back({x, y, c, idd});
        a[x][y] = a[x + 1][y + 1] = a[x + 1][y] = a[x][y + 1] = -1;
        for (int k = 0;k < 8;k ++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (check(nx, ny) && !vis[nx][ny]) 
                q.push({nx, ny, get(nx, ny), ++ id}), vis[nx][ny] = 1;
        }
    }
    reverse(all(ans));
    for (int i = 0;i < siz(ans);i ++) {
        int x = ans[i].x, y = ans[i].y, c = ans[i].c;
        bb[x][y] = bb[x + 1][y + 1] = bb[x + 1][y] = bb[x][y + 1] = c;
    }   
    if (aa == bb) {
        cout << siz(ans) << '\n';
        for (auto [x, y, c, id] : ans) cout << x << ' ' << y << ' ' << c << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}