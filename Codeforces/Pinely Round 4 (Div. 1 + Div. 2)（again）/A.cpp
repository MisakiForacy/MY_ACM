#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve () {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        if (i & 1) ans = max(ans, x);
    }
    cout << ans << '\n';
}

int main () {
    // freopen ("in", "r", stdin);
    // freopen ("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}