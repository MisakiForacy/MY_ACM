#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define siz(x) ((int) x.size())
using namespace std;
using LL = long long;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n - 1;i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dep(n + 1, 0);
    vector<vector<int>> fa(n + 1, vector<int>(20, 0));
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        dep[u] = dep[pu] + 1;
        fa[u][0] = pu;
        for (int i = 1;i <= 19;i ++){
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : g[u]){
            if (v == pu) continue;
            dfs(dfs, u, v);
        }
    };
    auto lca = [&](int u, int v) -> int {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19;i >= 0;i --){
            if (dep[fa[u][i]] >= dep[v]){
                u = fa[u][i];
            }
        }
        if (u == v) return u;
        for (int i = 19;i >= 0;i --){
            if (fa[u][i] != fa[v][i]){
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    };
    dfs(dfs, 0, 1);
    int q;
    cin >> q;
    while (q --){
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}