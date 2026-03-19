#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n;
    cin >> n;
    vector<vector<LL>> a(n + 1, vector<LL> (n + 1, 0));
    int x, y;
    LL mx = 0, mi = 1e15;
    for (int i = 1;i <= n;i ++) {
        LL sm = 0;
        for (int j = 1;j <= n;j ++) {
            cin >> a[i][j];
            if (!a[i][j]) {
                x = i, y = j;
            }
            sm += a[i][j];
        }
        mx = max(mx, sm);
        mi = min(mi, sm);
    }
    if (n == 1) {
        cout << 1 << '\n';
    } else {
        a[x][y] = mx - mi;
        int ok = 1;
        LL sm = 0;
        if (!a[x][y]) ok = 0;
        for (int i = 1;i <= n;i ++) sm += a[i][i];
        if (sm != mx) ok = 0;
        sm = 0;
        for (int i = 1;i <= n;i ++) sm += a[i][n - i + 1];
        if (sm != mx) ok = 0;
        for (int j = 1;j <= n;j ++) {
            sm = 0;
            for (int i = 1;i <= n;i ++) {
                sm += a[i][j];
            }
            if (sm != mx) ok = 0;
        }
        for (int i = 1;i <= n;i ++) {
            sm = 0;
            for (int j = 1;j <= n;j ++) {
                sm += a[i][j];
            }
            if (sm != mx) ok = 0;
        }
        cout << (ok ? a[x][y] : -1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}