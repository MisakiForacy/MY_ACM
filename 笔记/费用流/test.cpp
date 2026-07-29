#include <bits/stdc++.h>

#define x first 
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    vector<vector<LL>> f(n + 1, vector<LL> (n + 1, inf));
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i < n;i ++) f[i][i + 1] = 0;
    for (int len = 3;len <= n;len ++) {
        for (int l = 1;l + len - 1 <= n;l ++) {
            int r = l + len - 1;
            for (int k = l + 1;k < r;k ++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
            }
        }
    }
    cout << f[1][n] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}