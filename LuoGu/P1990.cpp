#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL mod = 1e9 + 7;

const int N = 1000005;

LL f[N][4];

void solve() {
    int n;
    cin >> n;
    f[0][3] = 1;
    for (int i = 1;i <= n;i ++) {
        f[i][0] += f[i - 1][3];
        f[i][1] += f[i - 1][2];
        f[i][1] += f[i - 1][0];
        f[i][2] += f[i - 1][1];
        f[i][2] += f[i - 1][0];
        f[i][3] += f[i - 1][1];
        f[i][3] += f[i - 1][2];
        f[i][3] += f[i - 1][3];
        if (i >= 2) f[i][3] += f[i - 2][3];
        for (int j = 0;j < 4;j ++) f[i][j] %= 10000; 
    }
    cout << f[n][3] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}