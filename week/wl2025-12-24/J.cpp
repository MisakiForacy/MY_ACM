#include <bits/stdc++.h>

#define x first 
#define y second 

using namespace std;
using LL = long long;

struct edge
{
    int u, v, w;
    bool operator < (const edge&T) const {
        return w > T.w;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, u, v, w;
    cin >> n >> m;
    vector<edge> p;
    for (int i = 1;i <= n - 1;i ++) {
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    vector<PII> q(m);
    for (int i = 0;i < m;i ++) cin >> q[i].x >> q[i].y;
    sort(all(q), [&](PII x, PII y) {return x.y < y.y; });
    vector<int> f(n + 1, 0), Sz(n + 1, 1);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto find = [&](auto find, int x) -> int {
        return (f[x] == x ? f[x] : f[x] = find(find, x));
    };
    auto merge = [&](int x, int y) -> void {
        x = find(find, x);
        y = find(find, y);
        if (x == y) return;
        if (x <  y) swap(x, y);
        f[x] = y;
    };
    LL Sm = 0;
    for (int i = 0;i < m;i ++) {

    }
    sort(all(q));
    for (auto [x, y] : q) cout << y << ' ';
    cout << '\n';
}