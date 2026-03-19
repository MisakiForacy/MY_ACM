#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Edge
{
    LL u, v, w;
    bool operator < (const Edge&T) const {
        return w < T.w;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    LL n, m, c;
    cin >> n >> m >> c;
    vector<Edge> edge;
    for (int i = 1;i <= m;i ++) {
        LL u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    vector<LL> f(n + 1, 0);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto find = [&](auto find, int x) -> int {
        if (f[x] != x) {
            f[x] = find(find, f[x]);
        }
        return f[x];
    };
    auto merge = [&](int x, int y) -> void {
        x = find(find, x);
        y = find(find, y);
        if (x == y) return;
        if (x  < y) swap(x, y);
        f[x] = y;
    };
    auto same = [&](int x, int y) -> bool {
        return (find(find, x) == find(find, y));
    };
    sort(edge.begin(), edge.end());
    auto check = [&](LL p) -> bool {
        for (int i = 1;i <= n;i ++) f[i] = i;
        vector<LL> use;
        LL Sm = 0;
        for (int i = 0;i < m;i ++) {
            if (edge[i].w <= p) {
                merge(edge[i].u, edge[i].v);
            } else {
                if (!same(edge[i].u, edge[i].v)) {
                    merge(edge[i].u, edge[i].v);
                    use.push_back(edge[i].w);
                }
            }
        }
        sort(use.begin(), use.end(), greater());
        for (int i = 0;i < use.size();i ++) {
            Sm += use[i] * (i + 1);
        }
        return Sm <= c;
    };
    LL cur = 0;
    for (LL j = 60;j >= 0;j --) {
        LL tmp = cur + (1LL << j);
        if (check(tmp)) continue;
        cur = tmp;
    }
    if (!check(cur)) cur += 1;
    cout << cur << '\n';
}