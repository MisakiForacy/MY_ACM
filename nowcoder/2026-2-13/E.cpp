#include <bits/stdc++.h>

#define double long double

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

struct node 
{
    LL h, u;
    bool operator < (const node&T) const {
        return h < T.h;
    }
};

void solve() {
    LL n, m, x, d;
    cin >> n >> m >> x >> d;
    vector<LL> h(n + 1, 0), H(x + 1, 0);
    vector<PLL> w(m + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i ++) cin >> h[i];
    for (int i = 1;i <= m;i ++) {
        cin >> w[i].x >> w[i].y;
        g[w[i].x].push_back(w[i].y);
        g[w[i].y].push_back(w[i].x);
    }
    int cnt = 0;
    for (int i = 1;i <= x;i ++) cin >> H[i];
    vector<int> f(n + 1, 0), Sz(n + 1, 1), on(n + 1, 0);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto find = [&](auto find, int u) -> int {
        if (u != f[u]) f[u] = find(find, f[u]);
        return f[u];
    };
    auto merge = [&](int u, int v) -> void {
        u = find(find, u);
        v = find(find, v);
        if (u == v) return;
        if (Sz[u] < Sz[v]) swap(u, v);
        if (Sz[u] >= d) cnt --;
        if (Sz[v] >= d) cnt --;
        f[v] = u;
        Sz[u] += Sz[v];
        if (Sz[u] >= d) cnt ++;
    };
    vector<int> ans(x + 1, 0);
    vector<node> Tp;
    Tp.reserve(n);
    for (int i = 1;i <= n;i ++) Tp.push_back({h[i], i});
    sort(all(Tp));
    int px = n - 1;
    for (int i = x;i >= 1;i --) {
        while (px >= 0 && Tp[px].h > H[i]) {
            int u = Tp[px].u;
            on[u] = 1;
            if (d == 1) cnt ++;
            for (auto v : g[u]) {
                if (on[v]) merge(v, u);
            }
            px --;
        }
        ans[i] = cnt;
    }
    for (int i = 1;i <= x;i ++) cout << ans[i] << '\n';
}

int main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}