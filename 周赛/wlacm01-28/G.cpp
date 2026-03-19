#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i < n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dep(n + 1, 0);
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        
    };
}
