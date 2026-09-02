#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

LL s[4];

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    int u, d, l, r;
    u = n, d = 1, l = m, r = 1;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            char c;
            cin >> c;
            a[i][j] = c == 'X';
            if (a[i][j]) {
                u = min(u, i);
                d = max(d, i);
                l = min(l, j);
                r = max(r, j);
            }
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    if (a[d][r] - a[d][l - 1] - a[u - 1][r] + a[u - 1][l - 1] == (d - u + 1) * (r - l + 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}