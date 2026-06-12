#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, k, mx = 0;
    cin >> n >> k;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        a[x] ++;
        mx = max(mx, x);
    }
    int lst = mx;
    if (a[mx] % 2 == 0) {
        cout << "YES\n";
        return;
    }
    for (int i = mx - 1;i >= 1;i --) {
        if (a[i] && lst - i <= k) {
            cout << "YES\n";
            return;
        } else if (a[i] && a[i] % 2 == 0) {
            cout << "YES\n";
            return;
        } else if (a[i]) {
            lst = i;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}