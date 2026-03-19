#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve () {
    LL n, h, ok = 1;
    cin >> n >> h;
    vector<LL> t(n + 1, 0), Mi(n + 1, 0), Mx(n + 1, 0);
    Mi[0] = Mx[0] = h;
    for (int i = 1;i <= n;i ++) {
        LL l, u;
        cin >> t[i] >> l >> u;
        LL d = t[i] - t[i - 1];
        Mi[i] = max(Mi[i - 1] - d, l);
        Mx[i] = min(Mx[i - 1] + d, u);
        if (Mx[i] < l || Mi[i] > u) ok = 0;
    }
    cout << (ok ? "Yes\n" : "No\n");
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}