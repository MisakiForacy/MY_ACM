#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const int N = 200005;
const LL inf = 1e15 + 1;

struct node
{
    LL u, w;
    bool operator < (const node&T) const {
        return w > T.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<node>> g(n + 1);
    LL x0, y0, c0;
    cin >> x0 >> y0 >> c0;
    for (int i = 2;i <= m;i ++) {
        LL x, y, c;
        cin >> x >> y >> c;
        g[x].push_back({y, c});
    }
    priority_queue<node> que;
    vector<LL> dis(n + 1, inf);
    vector<bool> vis(n + 1, 0);
    dis[y0] = 0;
    que.push({y0, 0});
    while (siz(que)) {
        auto [u, w] = que.top();
        que.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, qwq] : g[u]) {
            if (w + qwq >= dis[v]) continue;
            dis[v] = w + qwq;
            que.push({v, dis[v]});
        }
    }
    if (!vis[x0]) {
        cout << -1 << '\n';
    } else {
        cout << dis[x0] + c0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}

/*
4
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9
*/

/*
1 2 3 4
5 6 7 8
9

9 2 3 4
5 6 7 8
1

9 1 2 3
4 5 6 7
8
*/