#include <bits/stdc++.h>

using namespace std;
using LL = long long;

struct ed
{
    LL u, v, w;
    bool operator < (const ed&T) const {
        return T.w > w;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<LL>> a(n + 1, vector<LL> (n + 1));
    vector<ed> p;
    for (int i = 1;i <= n - 1;i ++) {
        for (int j = i + 1;j <= n;j ++) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
            p.push_back({i, j, a[i][j]});
            p.push_back({j, i, a[j][i]});
        }
    }
    sort(p.begin(), p.end());
    vector<LL> f(n + 1, 0);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto find = [&](auto find, int x) -> LL {
        return (f[x] == x ? f[x] : f[x] = find(find, f[x]));
    };
    auto merge = [&](int u, int v) -> void {
        u = find(find, u);
        v = find(find, v);
        if (u == v) return;
        if (u < v) swap(u, v);
        f[u] = v;
    };
    vector<vector<int>> g(n + 1);
    for (int i = 0;i < p.size();i ++) {
        if (find(find, p[i].u) == find(find, p[i].v)) continue;
        merge(p[i].u, p[i].v);
        g[p[i].u].push_back(p[i].v);
        g[p[i].v].push_back(p[i].u);
    }
    vector<LL> d(n + 1, 0);
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        d[u] = d[pu] + a[pu][u];
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u);
        }
    };
    int ok = 1;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) d[j] = 0;
        dfs(dfs, i, 0);
        for (int j = 1;j <= n;j ++) if (a[i][j] != d[j]) ok = 0;
    }
    cout << (ok ? "Yes\n" : "No\n");
}