#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int off = 100;

struct node
{
    LL x, y, d;
};

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0;i < n;i ++) cin >> x[i] >> y[i];
    queue<node> p;
    p.push({0, 0, 0});
    LL mi = 1e18;
    vector<vector<int>> vis(201, vector<int> (201, 0));
    while (p.size()) {
        auto [xx, yy, dd] = p.front();
        p.pop();
        if (xx == 0 && yy == 0 && dd != 0) {
            mi = min(mi, dd);
        }
        if (dd > 40000) continue;
        for (int i = 0;i < n;i ++) {
            int nx = xx + x[i];
            int ny = yy + y[i];
            if (nx < -100 || nx > 100 || ny < -100 || ny > 100 || vis[nx + off][ny + off]) continue;
            p.push({nx, ny, dd + 1});
            vis[nx + off][ny + off] = 1;
        }
    }
    cout << (mi == 1e18 ? -1 : mi) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}