#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int> dfn(n + 1, 0), low(n + 1, 0), scc(n + 1, 0), vis(n + 1, 0);
    stack<int> stk;
    int idx = 0, tot = 0;
    auto tarjan = [&](auto tarjan, int u) -> void {
        dfn[u] = low[u] = ++ idx;
        // cout << u << ' ' << dfn[u] << ' ' << low[u] << '\n';
        vis[u] = 1;
        stk.push(u);
        for (auto v : g[u]) {
            if (!dfn[v]) {
                tarjan(tarjan, v);
                low[u] = min(low[u], low[v]);
            } else if (vis[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        // cout << low[u] << ":\n";
        if (low[u] == dfn[u]) {
            tot ++;
            int v;
            do {
                v = stk.top();
                stk.pop();
                scc[v] = tot;
                vis[v] = 0;
            } while (v != u);
        }
    };
    for (int i = 1;i <= n;i ++) {
        if (!dfn[i]) {
            tarjan(tarjan, i);
        }
    }
    cout << "dfn : ";
    for (int i = 1;i <= n;i ++) {
        cout << dfn[i] << ' ';
    }
    cout << "\nlow : ";
    for (int i = 1;i <= n;i ++) {
        cout << low[i] << ' ';
    }
    cout << "\nscc : ";
    for (int i = 1;i <= n;i ++) {
        cout << scc[i] << ' ';
    }
}
