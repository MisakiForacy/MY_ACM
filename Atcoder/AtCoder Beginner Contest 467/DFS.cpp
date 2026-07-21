#include <bits/stdc++.h>

#define x first 
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<LL> v(n), a(n + 1), p(n + 1);
    for (int i = 1;i < n;i ++) cin >> v[i];
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL mi = 1e15, pre = 0, ans = 0;
    for (int i = 1;i < n;i ++) {
        pre += v[i];
        mi = min(mi, a[i]);
        if (pre > 0) {
            ans += (pre + d - 1) / d * mi; 
            pre -= (pre + d - 1) / d * d;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}



ans = 2^(n-1)
n = 2 2 
n = 3 4
n = 4 8
n = 5 16 
n = 6 32
6 
4! = 4 * 3 * 2 * 1 = 24

x x x 4  3! = 3 * 2 * 1 6
x x 4 x  3! 6
x x x 3  3! 6
x x 4 3  2! 2

24 - (6 + 6 - 2) - 6 = 8