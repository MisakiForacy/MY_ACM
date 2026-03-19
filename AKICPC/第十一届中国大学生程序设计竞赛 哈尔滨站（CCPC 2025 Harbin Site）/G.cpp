#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

#define LOG 20

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

void solve () {
    int n, m;
    cin >> n >> m;
    vector<vector<LL>> a(n + 2, vector<LL> (m + 2, 0));
    for (int i = 1;i <= n;i ++) for (int j = 1;j <= m;j ++) cin >> a[i][j];
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            if (a[i][j] < 0) {
                for (int t = j - 1;t >= 1;t --) {
                    if (a[i][t] > 0) {
                        if (a[i][t] > abs(a[i][j])) {
                            a[i][t] -= abs(a[i][j]);
                            a[i][j] = 0;
                        } else {
                            a[i][j] += a[i][t];
                            a[i][t] = 0;
                        }
                    }
                }
            }
        }
        for (int j = 1;j <= m;j ++) {
            if (a[i][j] > 0) {
                a[i + 1][j] += a[i][j];
                a[i][j] = 0;
            }
        }
    }
    LL ans = 0;
    for (int i = 1;i <= n + 1;i ++) {
        for (int j = 1;j <= m;j ++) {
            ans += abs(a[i][j]);
        }
    }
    cout << ans << '\n';
}

/*
3
1 1
5
1 2
1 -1
2 2
-1 0
1 1
*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}