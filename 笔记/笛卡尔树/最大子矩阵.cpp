#include <bits/stdc++.h>
#define x first 
#define y second
using namespace std;
using LL = long long;

int main() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    stack<pair<int, int>> stk;
    vector<int> ls(n + 1, 0), rs(n + 1, 0);
    int root;
    for (int i = 1;i <= n;i ++) {
        int lst = 0;
        if (stk.empty()) {
            root = i;
            stk.push({i, a[i]});
        } else {
            while (!stk.empty() && stk.top().y > a[i]) {
                lst = stk.top().x;
                stk.pop();
            }
            if (stk.empty()) {
                root = i;
                ls[i] = lst;
                stk.push({i, a[i]});
            } else {
                rs[stk.top().x] = i;
                ls[i] = lst;
                stk.push({i, a[i]});
            }
        }
    }
    vector<LL> siz(n + 1, 0);
    LL ans = 0;
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        siz[u] = 1;
        if (ls[u]) dfs(dfs, u, ls[u]), siz[u] += siz[ls[u]];
        if (rs[u]) dfs(dfs, u, rs[u]), siz[u] += siz[rs[u]];
        ans = max(ans, siz[u] * a[u]);
    };
    dfs(dfs, 0, root);
    cout << ans << '\n';
}