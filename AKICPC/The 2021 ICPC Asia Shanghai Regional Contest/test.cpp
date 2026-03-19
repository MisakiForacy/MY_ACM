#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;

const LL inf = 1e18;

struct node 
{
    LL v, w;
    bool operator < (const node&that) const {
        return w > that.w;
    }
};

void solve() {
    LL n, m, H;
    cin >> n >> m >> H;
    vector<vector<node>> g((n + 2) * (H + 2));
    vector<LL> a(n + 1, 0);
    vector<vector<LL>> dp(n + 1, vector<LL> (H + 1, 0));
    int cur = 0;
    for (int j = 0;j <= H;j ++) for (int i = 1;i <= n;i ++) dp[i][j] = ++ cur;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= m;i ++) {
        LL u, v, w;
        cin >> u >> v >> w;
        for (int j = 0;j <= H;j ++) {
            LL h1 = (a[v] - a[u] >= 0 ? a[v] - a[u] + j : 0);
            LL h2 = (a[u] - a[v] >= 0 ? a[u] - a[v] + j : 0);
            if (h1 <= H) g[dp[u][j]].push_back({dp[v][h1], w});
            if (h2 <= H) g[dp[v][j]].push_back({dp[u][h2], w});
        }
    }
    priority_queue<node> q;
    vector<LL> dis((n + 2) * (H + 2), inf);
    vector<bool> vis((n + 2) * (H + 2), 0);
    q.push({1, 0});
    dis[1] = 0;
    while (siz(q)) {
        auto [u, w] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, qwq] : g[u]) {
            if (w + qwq < dis[v]) {
                dis[v] = min(dis[v], w + qwq);
                q.push({v, dis[v]});
            }
        }
    }
    for (int i = 2;i <= n;i ++) {
        LL Min = inf;
        for (int j = 0;j <= H;j ++) {
            Min = min(Min, dis[dp[i][j]]);
        }
        cout << (Min == inf ? -1 : Min) << ' ';
    }
    cout << '\n';
}

/*
6 7 3
1 2 3 4 5 6
1 2 1
2 4 10
1 3 8
2 3 2
3 5 9
4 3 100
2 6 2
*/

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}