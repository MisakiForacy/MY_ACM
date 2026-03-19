#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL Mx = - 1e9;
    for (int i = 2;i <= n;i ++) {
        Mx = max(Mx, a[i] + a[i - 1]);
    }
    Mx = max(Mx, a[1] + k);
    Mx = max(Mx, a[n] + k);
    cout << Mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}