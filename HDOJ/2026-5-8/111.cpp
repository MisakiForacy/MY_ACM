#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j < n;j ++) {
            cin >> a[i][j];
        }
    }
    for (int k = 1;k <= n * n;k ++) {
        int okk = 1;
        for (int i = 0;i < n;i ++) {
            int ok = 0;
            for (int j = 0;j < n;j ++) {
                if (a[i][j] == k) ok = 1;
            }
            okk = min(okk, ok);
            if (okk == 0) break;
        }
        if (okk == 0) continue;
        for (int i = 0;i < n;i ++) {
            int ok = 0;
            for (int j = 0;j < n;j ++) {
                if (a[j][i] == k) ok = 1;
            }
            okk = min(okk, ok);
            if (okk == 0) break;
        }
        if (okk) ans.push_back(k);
    }
    cout << ans.size() << '\n';
    for (auto v : ans) cout << v << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}