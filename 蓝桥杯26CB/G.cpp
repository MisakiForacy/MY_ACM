#include <bits/stdc++.h>

#define siz(x) ((int)x.size()) 
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), b(n + 1), d(n + 1, 0), p(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i], d[i] = a[i] - b[i];
    for (int i = 1;i <= n;i ++) p[i] = p[i - 1] + (d[i] == 0);
    map<LL, vector<LL>> mp;
    for (int i = 1;i <= n;i ++) mp[d[i]].push_back(i);
    LL ans = p[n];
    for (auto [k, v] : mp) {
        LL mi = inf;
        for (LL i = 0;i < siz(v);i ++) {
            LL cur = i - p[v[i]];
            mi = min(mi, i - p[v[i] - 1]);
            ans = max(ans, cur - mi + p[n] + 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}