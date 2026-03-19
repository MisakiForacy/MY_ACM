#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second

using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

const LL inf = 1e15;

/*
2
5 2
1 1 2 2
6 2
1 1 2 2 3
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<LL> Val(n + 1, 0);
    for (int i = 2;i <= n;i ++) {
        int fa; cin >> fa;
        g[i].push_back(fa);
        g[fa].push_back(i);
    }
    LL Cnt = 0;

    for (int i = 1;i <= n;i ++) Val[i] = i - 1;

    vector<LL> dp(n + 1, 0);
    vector<set<int>> P(n + 1);

    auto Mex = [&](set<int> st) -> LL {
        for (int i = 0;i <= n + 1;i ++) {
            if (!st.count(i)) return i;
        }
    };

    auto dfs1 = [&](auto dfs1, int u, int pu) -> void {
        if (siz(g[u]) == 1 && u != 1) {
            P[u].insert(Val[u]);
            dp[u] = Mex(P[u]);
            return;
        }
        P[u].insert(Val[u]);
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs1(dfs1, v, u);
            for (auto x : P[v]) P[u].insert(x);
        }
        dp[u] = Mex(P[u]);
    };

    LL Mx = 0;
    vector<LL> MxP;
    // auto dfs = [&](auto dfs, int p) -> void {
    //     if (p > n) {
    //         // cout << "[";
    //         for (int i = 1;i <= n;i ++) {
    //             // cout << Val[i] << ",]"[i == n];
    //             dp[i] = 0;
    //             P[i].clear();
    //         }
    //         // cout << " : ";
    //         dfs1(dfs1, 1, 0);
    //         LL Sm = 0;
    //         for (int i = 1;i <= n;i ++) Sm += dp[i];
    //         // cout << Sm << '\n';
    //         Mx = max(Mx, Sm);
    //         if (Sm == Mx) MxP = Val;
    //         Cnt ++;
    //         return;
    //     }
    //     for (int j = 0;j <= n;j ++) {
    //         Val[p] = j;
    //         dfs(dfs, p + 1);
    //     }
    // };
    // dfs(dfs, 1);
    do {
        for (int i = 1;i <= n;i ++) 
            dp[i] = 0, P[i].clear();
        dfs1(dfs1, 1, 0);
        LL Sm = 0;
        for (int i = 1;i <= n;i ++) Sm += dp[i];
        Mx = max(Mx, Sm);
    } while (next_permutation(Val.begin() + 1, Val.end()));
    for (int i = 2;i <= n;i ++) Val[i] = i - 2;
    do {
        for (int i = 1;i <= n;i ++) 
            dp[i] = 0, P[i].clear();
        dfs1(dfs1, 1, 0);
        LL Sm = 0;
        for (int i = 1;i <= n;i ++) Sm += dp[i];
        Mx = max(Mx, Sm);
    } while (next_permutation(Val.begin() + 1, Val.end()));
    cout << Mx << '\n';
    // for (int i = 1;i <= n;i ++) cout << MxP[i] << " \n";
    // while (1) {
    //     cout << "Construct : \n";
    //     for (int i = 1;i <= n;i ++) cin >> Val[i], P[i].clear();
    //     dfs1(dfs1, 1, 0);
    //     LL Sm = 0;
    //     for (int i = 1;i <= n;i ++) Sm += dp[i];
    //     cout << Sm << '\n';
    // }
    // cout << Cnt << ' ' << Mx << '\n';
    // for (int i = 1;i <= n;i ++) cout << MxP[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}