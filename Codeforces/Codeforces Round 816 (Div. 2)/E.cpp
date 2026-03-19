#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e18;

struct node
{
    LL v, w;
    bool operator < (const node&T) const 
    {
        return w > T.w;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<node>> g(n + 1);
    for (int i = 1;i <= m;i ++) {   
        LL u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<LL> d(n + 1, inf), d1(n + 1, inf);
    auto dij = [&]() -> void {
        priority_queue<node> q;
        vector<bool> vis(n + 1, 0);
        d[1] = 0;
        for (int i = 1;i <= n;i ++) q.push({i, d[i]});
        while (siz(q)) {
            auto [u, w] = q.top();
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [v, qwq] : g[u]) if (w + qwq < d[v]) {
                d[v] = w + qwq;
                q.push({v, d[v]});
            }
        }
    };
    auto dfs = [&](auto dfs, int l, int r, int L, int R) -> void {
        if (l > r) return;
        LL mid = l + r >> 1;
        LL val = d1[mid], p = mid;
        for (int i = L;i <= R;i ++) if (d[i] + (i - mid) * (i - mid) < val) {
            val = d[i] + (i - mid) * (i - mid);
            p = i;
        }
        d1[mid] = val;
        dfs(dfs, l, mid - 1, L, p);
        dfs(dfs, mid + 1, r, p, R);
    };
    dij();
    for (int i = 1;i <= k;i ++) {
        dfs(dfs, 1, n, 1, n);
        swap(d, d1);
        dij();
    }
    for (int i = 1;i <= n;i ++) cout << d[i] << ' ';
    cout << '\n';
}

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}