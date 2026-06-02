#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n, m;
    cin >> n;
    vector<LL> alls;
    vector<PLL> p(n), q(n);
    for (int i = 0;i < n;i ++) {
        cin >> p[i].x >> p[i].y;
        alls.push_back(p[i].x);
        alls.push_back(p[i].y);
    }
    cin >> m;
    for (int i = 0;i < m;i ++) {
        cin >> q[i].x >> q[i].y;
        alls.push_back(q[i].x);
        alls.push_back(q[i].y);
    }
    sort(all(alls));
    alls.erase(unique(all(alls)), alls.end());
    int l = siz(alls);
    vector<vector<int>> g(l + 1);
    for (int i = 0;i < n;i ++) {
        p[i].x = lower_bound(all(alls), p[i].x) - alls.end() + 1;
        p[i].y = lower_bound(all(alls), p[i].y) - alls.end() + 1;
        g[p[i].x].push_back(p[i].y);
    }
    for (int i = 0;i < m;i ++) {
        q[i].x = lower_bound(all(alls), q[i].x) - alls.end() + 1;
        q[i].y = lower_bound(all(alls), q[i].y) - alls.end() + 1;
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}