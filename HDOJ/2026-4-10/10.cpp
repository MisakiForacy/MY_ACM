#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int> (m + 1, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cin >> a[i][j];
        }
    }
    int cur = 0, ok = 1;
    for (int i = 1;i <= n;i ++) {
        int mi = 500;
        for (int j = 1;j <= m;j ++) {
            if (a[i][j] > cur) {
                mi = min(mi, a[i][j]);
            }
        }
        if (mi == 500) ok = 0;
        cur = mi;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}