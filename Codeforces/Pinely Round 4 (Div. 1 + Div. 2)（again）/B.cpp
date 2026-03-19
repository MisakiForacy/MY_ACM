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
    vector<int> a(n + 2, 0), b(n + 1);
    for (int i = 2;i <= n;i ++) cin >> a[i];
    b[1] = a[2];
    for (int i = 2;i <= n;i ++) {
        b[i] = a[i] | a[i + 1];
    }
    int ok = 1;
    for (int i = 2;i <= n;i ++) 
        if ((b[i] & b[i - 1]) != a[i])    
            ok = 0;
    if (ok) {
        for (int i = 1;i <= n;i ++) cout << b[i] << ' ';
        cout << '\n';
    } else {
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