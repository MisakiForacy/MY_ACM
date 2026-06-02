#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

struct edge
{
    LL u, v, w;
    bool operator < (const edge&T) const {
        return w < T.w;
    }
};

struct node
{
    LL v, w;
    bool operator < (const node&T) const {
        return w > T.w;
    }
};

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k + 1);
    vector<edge> p;
    map<int, int> mp;
    for (int i = 1;i <= k;i ++) cin >> a[i], mp[a[i]] = 1;
    vector<int> f(n + 1, 0);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto find = [&](auto find, int x) -> int {
        return (f[x] == x ? f[x] : f[x] = find(find, f[x]));
    };
    auto merge = [&](int x, int y) -> void {
        x = find(find, x);
        y = find(find, y);
        if (x < y) swap(x, y);
        f[x] = y;
    };
    LL mi = 1e18;
    vector<priority_queue<node>> g(n + 1);
    for (int i = 0;i < m;i ++) {
        LL u, v, w;
        cin >> u >> v >> w;
        if (u == v) continue;
        mi = min(mi, w);
        if (mp.count(u) && mp.count(v)) continue;
        if (mp.count(u)) {
            g[u].push({v, w});
        } else if (mp.count(v)) {
            g[v].push({u, w});
        } else {
            p.push_back({u, v, w});
        }
    }
    sort(all(p));
    LL ans = 0;
    for (int i = 0;i < siz(p);i ++) {
        if (find(find, p[i].u) != find(find, p[i].v)) {
            merge(p[i].u, p[i].v);
            ans += p[i].w;
        }
    }
    for (int i = 1;i <= k;i ++) {
        if (g[a[i]].empty()) continue;
        merge(a[i], g[a[i]].top().v);
        ans += g[a[i]].top().w;
    }
    for (int i = 1;i <= n;i ++) if (find(find, i) != find(find, 1)) ans = -1;
    if (n == 2 && mi != 1e18) ans = mi;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}