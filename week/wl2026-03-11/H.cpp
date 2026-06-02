#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n + 1, 0), b(m + 1, 0), pos(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], pos[a[i]] = i - 1;
    for (int i = 1;i <= m;i ++) cin >> b[i];
    LL dep = -1;
    LL ans = 0;
    LL use = 0;
    for (int i = 1;i <= m;i ++) {
        // cout << pos[b[i]] << ' ';
        if (pos[b[i]] > dep) {
            ans += (pos[b[i]] - use) * 2 + 1;
            dep = max(dep, pos[b[i]]);
            use ++;
        } else {
            ans += 1;
            use ++;
        }
        // cout << ans << ' ' << dep << '\n';
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}