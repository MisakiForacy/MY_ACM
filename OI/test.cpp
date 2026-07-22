#include <bits/stdc++.h>

#define lowbit(x) (x & (-x))

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), fa(n + 1, 0), alls;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i], alls.push_back(a[i]);
    for (int i = 2;i <= n;i ++) 
        cin >> fa[i], g[fa[i]].push_back(i);
    vector<int> f(n + 1, 0), ans(n + 1, 0);
    
    sort(all(alls));

    for (int i = 1;i <= n;i ++)
        a[i] = lower_bound(all(alls), a[i]) - alls.begin() + 1;

    auto add = [&](int x, int val) -> void {
        for (;x <= n;x += lowbit(x)) f[x] += val;
    };

    auto qry = [&](int x) -> int {
        int sum = 0;
        for (;x;x -= lowbit(x)) sum += f[x];
        return sum;
    };

    vector<int> sz(n + 1, 0), mx(n + 1, 0), son(n + 1, 0);

    auto dfs0 = [&](auto dfs0, int u) -> void {
        sz[u] = 1;
        for (int v : g[u]) {
            dfs0(dfs0, v);
            sz[u] += sz[v];
            if (sz[v] > mx[u]) {
                mx[u] = sz[v];
                son[u] = v;
            }
        }
    };

    dfs0(dfs0, 1);

    cout << "OK\n";

    for (int i = 1;i <= n;i ++) {
        cout << fa[i] << ' ';
        cout << son[i] << '\n';
    }
    getchar();
    getchar();

    auto modify = [&](auto modify, int u, int val) -> void {
        add(u, val);
        for (int v : g[u]) {
            modify(modify, v, val);
        }
    };

    auto dfs = [&](auto dfs, int u, int s) -> void {
        cout << u << "  OK\n";
        for (int v : g[u]) {
            if (v == son[u]) continue;
            dfs(dfs, v, 0);
            modify(modify, v, 1);
            ans[u] = qry(n) - qry(a[v]);
            modify(modify, v, -1);
        }
        if (s) {
            dfs(dfs, son[u], 1);
            modify(modify, son[u], 1);
            ans[son[u]] = qry(n) - qry(a[son[u]]);
        }
        for (int v : g[u]) {
            if (v == son[u]) continue;
            modify(modify, v, 1);
        }
    };

    dfs(dfs, 1, 1);
    for (int i = 1;i <= n;i ++) cout << ans[i] << '\n';
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
