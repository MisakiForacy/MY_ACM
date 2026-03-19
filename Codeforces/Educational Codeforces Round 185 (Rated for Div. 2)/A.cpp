#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve () {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 2, vector<int> (n + 2, 0));
    vector<vector<int>> p(n + 2, vector<int> (n + 2, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            a[i][j] = (i - 1) * n + j;
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            p[i][j] = a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1];
            ans = max(ans, p[i][j]);
        }
    }
    cout << ans << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}