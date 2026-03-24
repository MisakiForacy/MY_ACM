#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    stack<pair<int, int>> stk;
    vector<int> ls(n + 1), rs(n + 1), fa(n + 1);
    for (int i = 1;i <= n;i ++) {
        int lst = 0;
        if (stk.empty()) {
            stk.push({a[i], i});
        } else {
            while (!stk.empty() && stk.top().x < a[i]) {
                lst = stk.top().y;
                stk.pop();
            }
            if (stk.empty()) {
                ls[i] = lst;
                fa[lst] = i;
                stk.push({a[i], i});
            } else {
                rs[stk.top().y] = i;
                ls[i] = lst;
                fa[i] = stk.top().y;
                fa[lst] = i;
                stk.push({a[i], i});
            }
        }
    }
    vector<pair<int, int>> p;
    for (int i = 1;i <= n;i ++) p.push_back({a[i], i});
    sort(all(p), [&](pair<int, int> a, pair<int, int> b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    LL ans = (1 + n) * n / 2;
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        
    };
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}