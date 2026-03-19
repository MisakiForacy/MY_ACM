#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

const int N = 2e5 + 10;

const LL inf = 1e15;

struct edge
{
    LL u, v, w;
    bool operator < (const edge&that) const {
        return w < that.w;
    }
};

void solve() {
    LL n, m, q;
    cin >> n >> m >> q;
    vector<LL> a(n + 1, 0);
    vector<edge> p(m);
    vector<LL> f(n << 1 | 1, 0), val(n << 1 | 1);
    int cur = n;
    vector<vector<LL>> fa(n << 1 | 1, vector<LL> (20 ,0));
    vector<vector<LL>> dp(n << 1 | 1, vector<LL> (20 ,0));
    for (int i = 1;i <= 2 * n;i ++) f[i] = i;
    auto findx = [&](auto findx, int x) -> int {
        if (f[x] != x) {
            f[x] = findx(findx, f[x]);
        }
        return f[x];
    };
    auto merge = [&](int u, int v, int w) -> void {
        u = findx(findx, u);
        v = findx(findx, v);
        if (u != v) {
            f[u] = f[v] = ++ cur;
            f[cur] = cur;
            val[cur] = w;
            val[cur] = val[u] + val[v];
            fa[u][0] = fa[v][0] = cur;
            dp[u][0] = w - val[u];
            dp[v][0] = w - val[v];
        }
    };
    for (int i = 1;i <= n;i ++) cin >> a[i], val[i] = a[i];
    for (int i = 0;i < m;i ++) cin >> p[i].u >> p[i].v >> p[i].w;
    sort(all(p));
    for (auto [u, v, w] : p) {
        if (findx(findx, u) != findx(findx, v)) {
            merge(u, v, w);
        }
    }
    for (int j = 1;j <= 19;j ++) {
        for (int i = 1;i <= cur;i ++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            dp[i][j] = max(dp[i][j - 1], dp[fa[i][j - 1]][j - 1]);
        }
    }
    val[0] = val[cur];
    while (q --) {
        LL x, k;
        cin >> x >> k;
        for (int i = 19;i >= 0;i --) {
            if (dp[x][i] <= k && x) {
                x = fa[x][i];
            }
        }
        cout << val[x] + k << '\n';
    }
}

/*
8 10 2
3 1 4 1 5 9 2 6
1 2 7
1 3 11
2 3 13
3 4 1
3 6 31415926
4 5 27182818
5 6 1
5 7 23333
5 8 55555
7 8 37
1 7
8 30
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