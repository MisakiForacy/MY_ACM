#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

#define x first 

#define y second 

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

const int N = 25;

int n;
LL f[N][N];

// void dfs(int pos) {

// }

void solve() {
    cin >> n;
    for (int i = 1;i <= 3 * n;i ++) {
        for (int j = 1;j <= 3 * n;j ++) {
            cin >> f[i][j];
        }
    }
}

int main() {
    int cnt = 0;
    int ff[10];
    for (int i = 0;i < (1LL << 24);i ++) {
        if (__builtin_popcount(i) % 3 == 0) cnt ++;
    }
    LL tot = 0;
    for (int i = 3;i <= 24;i += 3) {
        LL v = 1;
        for (int j = i;j > i - 3;j --) {
            v *= j;
        }
        v /= 6;
        tot += v;
        cout << v << ' ';
    }
    cout << '\n';
    cout << tot << '\n';
    cout << cnt << '\n';
    // ios::sync_with_stdio(0), cin.tie(0);
    // int T = 1;
    // // cin >> T;
    // while (T --) solve();
}
