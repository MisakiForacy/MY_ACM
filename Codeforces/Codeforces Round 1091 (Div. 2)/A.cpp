#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n + 1);
    LL s = 0;
    for (int i = 1;i <= n;i ++) cin >> a[i], s += a[i];
    if (s & 1) {
        cout << "YES\n";
    } else {
        if ((n * k) & 1) {
            cout << "NO\n";
        } else { 
            cout << "YES\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}