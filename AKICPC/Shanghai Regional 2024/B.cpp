#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first 
#define y second 
using namespace std;
using LL = long long;

const LL MOD = 998244353;

/*
6 6
1 3
1 4
2 3
3 4
3 6
5 6
1 2 3 4 5 6
*/

/*
8 8
2 8
3 8
5 6
1 6
6 3
8 7
2 3
4 3
1 8 7 5 4 2 3 6
*/

/*
5 4 
1 2
1 3
2 4
2 5
1 2 3 4 5
*/

/*
5 4 
1 2
1 3
2 4
2 5
1 2 5 4 3
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n + 1);
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    vector<int> p(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> p[i];
    vector<pair<int, int>> ans;
    g[0].insert(p[1]);
    g[p[1]].insert(0);
    vector<int> vis(n + 1, 0);
    vector<int> fa(n + 1, -1);
    for (int i = 1;i <= n;i ++) {
        int u = p[i - 1], v = p[i];
        vis[u] = 1;
        if (g[u].find(v) == g[u].end()) {
            int cur = u, ok = 0;
            while (g[cur].find(v) == g[cur].end() && cur) {
                vector<int> ers;
                for (int x : g[cur])
                    if (vis[x])
                        ers.push_back(x);
                for (int x : ers) g[cur].erase(x);
                if (g[cur].size()) {
                    ans.push_back({cur, v});
                    fa[v] = cur;
                    ok = 1;
                    break;
                } else {
                    cur = fa[cur];
                }
            }
            if (!ok) fa[v] = cur;
        } else {
            g[u].erase(v);
            fa[v] = u;
        }
    }
    cout << siz(ans) << '\n';
    for (auto [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}