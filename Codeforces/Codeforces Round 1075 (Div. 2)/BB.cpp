#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x;
        cin >> n >> x;
        ll totalC = 0;          // sum of a_i*(b_i-1)
        ll maxD = 0;            // maximum positive d_i = a_i*b_i - c_i
        for (int i = 0; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            totalC += a * (b - 1);
            ll d = a * b - c;
            if (d > maxD) {
                maxD = d;
            }
        }
        if (x <= totalC) {
            cout << 0 << '\n';
        } else {
            if (maxD <= 0) {
                cout << -1 << '\n';
            } else {
                ll D = x - totalC;
                ll ans = (D + maxD - 1) / maxD;   // ceil(D / maxD)
                cout << ans << '\n';
            }
        }
    }
    return 0;
}