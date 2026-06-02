#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<map<int, int>> g(n + 1);
    for (int i = 1;i <= n;i ++) {
        int k, x;
        cin >> k;
        for (int j = 1;j <= k;j ++) {
            cin >> x;
            g[i][x] = 1;
        }
    }
    int q;
    cin >> q;
    while (q --) {
        int x, y, cnt = 0;
        cin >> x >> y;
        for (int i = 1;i <= n;i ++) if (g[i][x] && g[i][y]) cnt ++;
        cout << cnt << '\n';
    }
}

int main() {
    cout << fixed << setprecision(2);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}