#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    int a[n + 1] = {0}, mx = 0;
    for (int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        a[x] ++;
        mx = max(mx, a[x]);
    }
    cout << n - mx << '\n';
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
