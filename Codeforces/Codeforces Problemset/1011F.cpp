#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    map<string, int> mp; 
    mp["IN"] = 1, mp["NOT"] = 2, mp["AND"] = 3, mp["OR"] = 4, mp["XOR"] = 5;
    vector<int> dp(n + 1, 0), Ls(n + 1, 0), Rs(n + 1, 0), Fa(n + 1, 0), op(n + 1, 0);
    vector<int> use(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        string opt;
        int x, y;
        cin >> opt;
        op[i] = mp[opt];
        if (op[i] == 1) {
            cin >> x;
            dp[i] = x;
        } else if (op[i] == 2) {
            cin >> x;
            Fa[x] = i;
            Ls[i] = x; 
        } else if (op[i] > 2) {
            cin >> x >> y;
            Fa[x] = Fa[y] = i;
            Ls[i] = x, Rs[i] = y;
            if (op[i] == 3) dp[i] = 1;
        }
    }
    auto Opt = [&](int u, int v, int opt) -> void {
        if (opt == 2) dp[u] = !dp[v];
        if (opt == 3) dp[u] &= dp[v];
        if (opt == 4) dp[u] |= dp[v];
        if (opt == 5) dp[u] ^= dp[v];
    };
    use[1] = 1;
    auto dfs = [&](auto dfs, int pu = 0, int u = 1) -> void {
        if (Ls[u]) dfs(dfs, u, Ls[u]), Opt(u, Ls[u], op[u]);
        if (Rs[u]) dfs(dfs, u, Rs[u]), Opt(u, Rs[u], op[u]);
    };
    dfs(dfs);
    auto DFS = [&](auto DFS, int pu = 0, int u = 1, int s = 1) -> void {
        if (use[pu]) {
            if (op[pu] == 2) use[u] = 1;
            if (op[pu] == 3) {
                if (s == 1) {
                    if (dp[u] == 0 && dp[Rs[Fa[u]]] == 1) use[u] = 1;
                    if (dp[u] == 1 && dp[Rs[Fa[u]]] == 1) use[u] = 1;
                } else {
                    if (dp[u] == 0 && dp[Ls[Fa[u]]] == 1) use[u] = 1;
                    if (dp[u] == 1 && dp[Ls[Fa[u]]] == 1) use[u] = 1;
                }
            } 
            if (op[pu] == 4) {
                if (s == 1) {
                    if (dp[u] == 0 && dp[Rs[Fa[u]]] == 0) use[u] = 1;
                    if (dp[u] == 1 && dp[Rs[Fa[u]]] == 0) use[u] = 1;
                } else {
                    if (dp[u] == 0 && dp[Ls[Fa[u]]] == 0) use[u] = 1;
                    if (dp[u] == 1 && dp[Ls[Fa[u]]] == 0) use[u] = 1;
                }
            }
            if (op[pu] == 5) {
                if (s == 1) {
                    if (dp[u] == 0 && dp[Rs[Fa[u]]] == 1) use[u] = 1;
                    if (dp[u] == 1 && dp[Rs[Fa[u]]] == 0) use[u] = 1;
                    if (dp[u] == 1 && dp[Rs[Fa[u]]] == 1) use[u] = 1;
                    if (dp[u] == 0 && dp[Rs[Fa[u]]] == 0) use[u] = 1;
                } else {
                    if (dp[u] == 0 && dp[Ls[Fa[u]]] == 1) use[u] = 1;
                    if (dp[u] == 1 && dp[Ls[Fa[u]]] == 0) use[u] = 1;
                    if (dp[u] == 1 && dp[Ls[Fa[u]]] == 1) use[u] = 1;
                    if (dp[u] == 0 && dp[Ls[Fa[u]]] == 0) use[u] = 1;
                }
            }
        }
        if (Ls[u]) DFS(DFS, u, Ls[u], 1);
        if (Rs[u]) DFS(DFS, u, Rs[u], 2);
    }; DFS(DFS);
    int base = dp[1];
    for (int i = 1;i <= n;i ++) {
        if (!Ls[i]) {
            if (use[i]) cout << !base;
            if (!use[i]) cout << base;
        }
    }
    cout << '\n';
}