#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int l, n;
    cin >> l >> n;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1, 0));
    vector<int> row(n + 1, 0);
    auto dfs = [&](auto dfs, int c, int r, int v) -> int {
        if (c == 1 && r == n) {
            for (int i = 1;i <= n - 1;i ++) {
                mp[i][n] = l;
                for (int j = 1;j <= n - 1;j ++) {
                    mp[i][n] -= mp[i][j];
                }    
                if (mp[i][n] < 0) return 0;
            }
            for (int j = 1;j <= n;j ++) {
                mp[n][j] = l;
                for (int i = 1;i <= n - 1;i ++) {
                    mp[n][j] -= mp[i][j];
                }
                if (mp[n][j] < 0) return 0;
            }
            return 1;
        }
        if (row[r] > l) return 0;
        int res = 0;
        for (int i = 0;i <= l - row[r];i ++) {
            mp[c][r] = i;
            row[r] += i;
            res += dfs(dfs, (c == n - 1 ? 1 : c + 1), (c == n - 1 ? r + 1 : r), v - i);
            mp[c][r] = 0;
            row[r] -= i;
        }   
        return res;
    };
    cout << dfs(dfs, 1, 1, l);
}

int main() {
    // cout << fixed << setprecision(2);
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}