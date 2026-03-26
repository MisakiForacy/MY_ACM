#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    int c[n + 1][n + 1];
    for (int i = 1;i <= n;i ++) {
        for (int j = i + 1;j <= n;j ++) {
            cin >> c[i][j];
        }
    }
    int ok = 0;
    for (int i = 1;i <= n;i ++) {
        for (int j = i + 1;j <= n;j ++) {
            for (int k = j + 1;k <= n;k ++) {
                int x = c[i][j];
                int y = c[j][k];
                int z = c[i][k];
                if (x + y < z) ok = 1;
            }
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}