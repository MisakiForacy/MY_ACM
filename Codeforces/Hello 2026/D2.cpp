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
    vector<int> dep(n + 1, 0), fa(n + 1, 0), son(n + 1, 0), C(n + 1, 0);
    map<int, vector<int>> mp;
    map<int, set<int>> S;
    map<int, map<int, int>> used; 
    auto get = [&](int u, int c, int p, int base) -> int {
        int cnt = 0;
        while (C[fa[u]] == c + base || used[dep[u]][c] && cnt <= p + 1) 
            c ++, c = (c - 1) % p + 1, cnt ++;
        used[dep[u]][c] = 1;
        if (cnt > p + 1) c = 0;
        return c;
    };
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        fa[u] = pu;
        dep[u] = dep[pu] + 1;
        mp[dep[u]].push_back(u);
        for (auto v : g[u]) {
            if (v == pu) continue;
            son[u] += 1;
            dfs(dfs, u, v);
        }
    };
    dfs(dfs, 0, 1);
    int Ans = 0, use, ok;
    for (int i = 1;i <= n;i ++) {
        LL Val = siz(mp[dep[i]]) + (son[fa[i]] == siz(mp[dep[i]]));
        if (Val > Ans) {
            Ans = Val;
            use = dep[i];
            ok = son[fa[i]] == siz(mp[dep[i]]);
        }
    }
    cout << Ans << '\n';
    auto dfs1 = [&](auto dfs1, int pu, int u, int rt) -> void {
        if ((dep[u] & 1) == (dep[rt] & 1)) C[u] = 1;
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs1(dfs1, u, v, rt);
            break;
        }
    };
    // cout << ok << '\n';
    if (ok) {
        // if (use & 1) {
        //     dfs1(dfs1, 1, 2, 2);
        // } else {
        //     dfs1(dfs1, 0, 1, 1);
        // }
        // cout << use << '\n';
        // cout << "DEBUG : ";
        // for (int i = 1;i <= n;i ++) cout << C[i] << ' ';
        // cout << '\n';
        int c = 1;
        for (auto [k, vec] : mp) {
            for (int u : vec) {
                if (C[u]) continue;
                // cout << k << ' ' << u << ':';
                C[u] = get(u, c, Ans - 1, 1) + 1;
                // for (int i = 1;i <= n;i ++) cout << C[i] << ' ';
                // cout << '\n';
            }
        }
        for (int i = 1;i <= n;i ++) if (!C[i]) C[i] = 1;
    } else {
        int c = 1;
        for (auto [k, vec] : mp) {
            for (int u : vec) {
                C[u] = get(u, c, Ans, 0);
            }
        }
    }
    map<int, vector<int>> ret;
    for (int i = 1;i <= n;i ++) ret[C[i]].push_back(i);
    for (auto [k, vec] : ret) {
        cout << siz(vec) << ' ';
        for (auto x : vec) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}