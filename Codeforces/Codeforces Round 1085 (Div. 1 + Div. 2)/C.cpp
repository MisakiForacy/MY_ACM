#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    LL n, h;
    cin >> n >> h;
    vector<LL> a(n + 2, h);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<LL> ls(n + 1, 0), rs(n + 1, 0), fa(n + 1, 0);
    stack<pair<int, LL>> stk;
    for (int i = 1;i <= n;i ++) {
        int lst = 0;
        if (stk.empty()) {
            stk.push({i, h - a[i]});
        } else {
            while (siz(stk) && stk.top().y > a[i]) {
                lst = stk.top().x;
                stk.pop();
            }
            if (siz(stk)) {
                fa[lst] = i;
                ls[i] = lst;
                stk.push({i, h - a[i]});
            } else {
                fa[i] = stk.top().x;
                rs[stk.top().x] = i;
                fa[lst] = i;
                ls[i] = lst;
                stk.push({i, h - a[i]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}