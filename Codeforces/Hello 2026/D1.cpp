#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const int N = 200005;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 2;i <= n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int Ans = 0;
    vector<int> dep(n + 1, 0), fa(n + 1, 0), son(n + 1, 0);
    map<int, int> mp;
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        fa[u] = pu;
        dep[u] = dep[pu] + 1;
        mp[dep[u]] += 1;
        for (auto v : g[u]) {
            if (v == pu) continue;
            son[u] += 1;
            dfs(dfs, u, v);
        }
    };
    dfs(dfs, 0, 1);
    for (int i = 1;i <= n;i ++)
        Ans = max(Ans, mp[dep[i]] + (son[fa[i]] == mp[dep[i]]));
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}