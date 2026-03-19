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
    vector<LL> a(n + 1, 0), b;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= 40;i ++) {
        int ok = 1;
        for (int i = 1;i <= n;i ++) if (a[i]) ok = 0;
        if (ok) break;
        sort (all (a));
        int x = a[n] + a[1] >> 1;
        b.push_back(x);
        for (int i = 1;i <= n;i ++) a[i] = abs(a[i] - x);
    }
    int ok = 1;
    for (int i = 1;i <= n;i ++) if (a[i]) ok = 0;
    if (ok) {
        cout << siz(b) << '\n';
        for (int x : b) cout << x << ' ';
        cout << '\n';
    } else {
        // cout << siz(b) << '\n';
        // for (int x : b) cout << x << ' ';
        // cout << '\n';
        cout << -1 << '\n';
    }
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