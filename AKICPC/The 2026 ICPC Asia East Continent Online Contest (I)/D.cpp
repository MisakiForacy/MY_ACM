#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

const LL mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1;i <= n;i ++) cin >> p[i];
    sort(all(p));
    int ans = 0;
    for (int j = 0;j < (1LL << n);j ++) {
        vector<int> tp(n + 1);
        for (int i = 0;i < n;i ++) {
            for (int t = 0;t < i;t ++) {
                tp[i + 1] += ((j >> i & 1) != (j >> t & 1));                
            }
        } 
        sort(all(tp));
        if (tp == p) ans ++;
    }
    cout << ans << '\n';
    // vector<vector<LL>> f(n + 1, vector<LL> (2, 0));
    // LL f[n + 1][2][n + 1];
    // memset(f, 0, sizeof(f));
    // f[1][0][0] = f[1][1][1] = 1;
    map<LL, LL> f[n + 1][2];
    f[1][0][0] = f[1][1][1] = 1;
    for (int i = 2;i <= n;i ++) {
        // cout << i << '\n';
        f[i][0][p[i]] += f[i - 1][0][p[i]] + f[i - 1][1][p[i]];
        f[i][1][p[i]] += f[i - 1][0][i - p[i]] + f[i - 1][1][i - p[i]];
        f[i][0][i - p[i]] += f[i - 1][0][i - p[i]] + f[i - 1][1][i - p[i]];
        f[i][1][i - p[i]] += f[i - 1][0][p[i]] + f[i - 1][1][p[i]];
        f[i][0][p[i]] %= mod;
        f[i][1][p[i]] %= mod;
        f[i][0][i - p[i]] %= mod;
        f[i][1][i - p[i]] %= mod;
        cout << f[i][0][p[i]] << ' ' << f[i][1][p[i]] << '\n';
    }
    cout << (f[n][0][p[n]] + f[n][1][p[n]]) % mod << '\n';
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}