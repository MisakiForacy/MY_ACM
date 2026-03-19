#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    stack<pair<int, int>> stk;
    vector<int> ls(n + 1, 0), rs(n + 1, 0), fa(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        int lst = 0;
        if (!siz(stk)) {
            stk.push({i, a[i]});
        } else {
            while (siz(stk) && a[i] > stk.top().y) {
                lst = stk.top().x;
                stk.pop();
            }
            if (siz(stk)) {
                rs[stk.top().x] = i;
                ls[i] = lst;
                fa[i] = stk.top().x;
            } else {
                ls[i] = lst;
            }
            fa[lst] = i;
            stk.push({i, a[i]});
        }
    }
    int rt = 0;
    vector<int> dp(n + 1, 0), sz(n + 1, 0);
    for (int i = 1;i <= n;i ++) if (!fa[i]) rt = i;
    auto dfs = [&](auto dfs, int u) -> void {
        sz[u] = 1;
        if (ls[u]) dfs(dfs, ls[u]), sz[u] += sz[ls[u]];
        if (rs[u]) dfs(dfs, rs[u]), sz[u] += sz[rs[u]];
        dp[u] = min(dp[ls[u]] + sz[rs[u]], dp[rs[u]] + sz[ls[u]]);
    };
    dfs(dfs, rt);
    cout << dp[rt] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}