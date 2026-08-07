#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), p(32, 0);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    int f[n + 1][2];
    memset(f, 0, sizeof(f));
/*
0001
0000
0001
0110
0101
*/


    // f[i][1] 表示考虑到第j位时f[i]和f[i-1]高位都相同
    // f[i][0] 表示考虑到第j位时f[i]和f[i-1]高位不同
    for (int i = 1;i <= n;i ++) f[i][1] = 1;
    LL ans = 0;
    for (int j = 30;j >= 0;j --) {
        for (int i = 2;i <= n;i ++) {
            
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}