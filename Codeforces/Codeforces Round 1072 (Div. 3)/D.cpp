#include <bits/stdc++.h>

#define x first
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))

using namespace std;
using LL = long long;

LL C[35][35];

void solve() {
    LL n, k;
    cin >> n >> k;
    LL x = (LL)log2(n);
    LL cnt = 0;
    if (x + 1 <= k) cnt ++;
    for (LL j = x - 1;j >= 0;j --) {
        if (k - j - 1 < 0) continue;
        int use = min(k - j - 1, j);
        for (int t = 0;t <= use;t ++)
            cnt += C[j][t];
    }
    cout << n - cnt << '\n';
}

int main() {
    for (int i = 0;i < 32;i ++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1;j < i;j ++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}