#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve () {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n + 1, 0), b(n + 1, 0), p(n + 1, 0), s(n + 2, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], p[i] = p[i - 1] + a[i];
    for (int i = n;i >= 1;i --) s[i] = s[i + 1] + a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    vector<LL> LMi(n + 1, 0), RMi(n + 2, 0);
    for (int i = 1;i <= n;i ++) LMi[i] = min(LMi[i - 1], p[i]);
    for (int i = n;i >= 1;i --) RMi[i] = min(RMi[i + 1], s[i]);
    LL Mx = -1e18;
    for (int i = 1;i <= n;i ++) {
        LL V = a[i] + b[i] * (k & 1);
        V += max(0LL, p[i - 1] - LMi[i - 1]);
        V += max(0LL, s[i + 1] - RMi[i + 1]);
        Mx = max(Mx, V);
    }
    cout << Mx << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}