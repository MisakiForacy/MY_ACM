#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define int long long
#define double long double

using namespace std;
using LL = long long;
using ULL = unsigned long long;

const int P = 13331;
const double inf = 1e15;

struct node
{
    int u;
    double w;
    bool operator < (const node&T) const {
        return w > T.w;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n + 1);
    for (int i = 1;i <= n;i ++) cin >> p[i].x >> p[i].y;
    int sx, sy, tx, ty, v1, v2;
    cin >> sx >> sy >> tx >> ty;
    p[0] = {sx, sy};
    p.push_back({tx, ty});
    cin >> v1 >> v2;
    auto dir = [&](int u, int v, bool t1) -> double {
        int x1 = p[u].x, y1 = p[u].y;
        int x2 = p[v].x, y2 = p[v].y;
        double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if (t1) {
            if (v2 * 3 > d) {
                return d / v2;
            } else {
                return 3.0 + (d - (v2 * 3.0)) / v1;
            }
        } else {
            return d / v1;
        }
    };
    vector<vector<node>> g(n + 2);
    for (int i = 0;i < n + 1;i ++) {
        for (int j = 0;j <= n + 1;j ++) {
            double w;
            if (i == j) continue;
            w = dir(i, j, !(i == 0 || i == n + 1));
            g[i].push_back({j, w});
        }
    }
    priority_queue<node> q;
    vector<bool> vis(n + 3, 0);
    vector<double> dis(n + 3, inf);
    dis[0] = 0;
    q.push({0, 0});
    while (siz(q)) {
        auto [u, w] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, ww] : g[u]) {
            // cout << v << '\n';
            if (dis[v] > dis[u] + ww) {
                dis[v] = dis[u] + ww;
                q.push({v, dis[v]});
            }
        }
        // cout << "ok\n";
    }
    cout << dis[n + 1] << '\n';
}

signed main() {
    cout << fixed << setprecision(20);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}

// bca
// 