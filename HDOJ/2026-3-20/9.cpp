#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int off = 250;

struct node
{
    int x, y, d;
};

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0;i < n;i ++) cin >> x[i] >> y[i];
    queue<node> p;
    p.push({0, 0, 0});
    int mi = 1e18;
    vector<vector<int>> vis(500, vector<int> (500, 0));
    while (p.size()) {
        auto [xx, yy, dd] = p.front();
        p.pop();
        if (xx == 0 && yy == 0 && dd != 0) {
            mi = min(mi, dd);
        }
        if (dd > 200) continue;
        for (int i = 0;i < n;i ++) {
            int nx = xx + x[i];
            int ny = yy + y[i];
            if (nx < -200 || nx > 200 || ny < -200 || ny > 200 || vis[]) continue;
            p.push({nx, ny, dd + 1});
        }
    }
    cout << mi << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}