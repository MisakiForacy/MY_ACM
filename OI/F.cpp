#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<int, int>;

const double PI = 3.14159265358979323846;

void solve() {
    int n, B;
    cin >> n >> B;
    vector<vector<int>> g(n + 1);
    for (int i = 2;i <= n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    stack<int> stk;
    vector<int> Rt(n + 1, 0), col(n + 1, 0);
    int cnt = 0;
    auto dfs = [&](auto dfs, int u, int pu) -> void {
        int cur = siz(stk);
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, v, u);
            if (siz(stk) - cur >= B) {
                Rt[++ cnt] = u;
                while (siz(stk) > cur) {
                    col[stk.top()] = cnt;
                    stk.pop();
                }
            }
        }
        stk.push(u);
    };
    dfs(dfs, 1, 0);
    if (!cnt) Rt[++ cnt] = 1;
    while (siz(stk)) {
        col[stk.top()] = cnt;
        stk.pop();
    } 
    cout << cnt << '\n';
    for (int i = 1;i <= n;i ++) cout << col[i] << ' ';
    cout << '\n';
    for (int i = 1;i <= cnt;i ++) cout << Rt[i] << ' ';
    cout << '\n';
}
// 5 4 4 3 3 2 2 1 1
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}