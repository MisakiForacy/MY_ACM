#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 1005;
const int M = 6005;

int f[N][2 * M][2], a[N], b[N], c[N];

int main() {
    int n;
    cin >> n;
    // for (int i = 0;i < N;i ++) dp[i][0] = dp[i][1] = 1e8;
    for (int i = 0;i < N;i ++) 
        for (int j = 0;j < 2 * M;j ++) 
            f[i][j][0] = f[i][j][1] = 1e8;
    f[0][M][0] = f[0][M][1] = 0; 
    for (int i = 1;i <= n;i ++) {
        cin >> a[i] >> b[i];
        c[i] = a[i] - b[i];
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 0;j < 2 * M;j ++) {
            if (j + c[i] >= 0 && j + c[i] < 2 * M) {
                f[i][j + c[i]][0] = min(f[i - 1][j][0], f[i - 1][j][1]);
            } 
            if (j - c[i] >= 0 && j - c[i] < 2 * M) {
                f[i][j - c[i]][1] = min(f[i - 1][j][0], f[i - 1][j][1]) + 1;
            }
        }
    }
    int mi = 1e8, ans = 1e8;
    for (int j = 0;j < 2 * M;j ++) {
        if (f[n][j][0] != 1e8 || f[n][j][1] != 1e8) {
            if (abs(M - j) <= mi) {
                mi = abs(M - j);
            }
        }
    }
    // cout << mi << '\n';
    ans = min(ans, f[n][M - mi][0]);
    ans = min(ans, f[n][M - mi][1]);
    ans = min(ans, f[n][M + mi][0]);
    ans = min(ans, f[n][M + mi][1]);
    cout << ans << '\n';
}