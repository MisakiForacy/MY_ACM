#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    int ok = 1;
    int s0 = 0, s1 = 0;
    for (int i = 1;i <= n;i ++) {
        cout << a[i] << ':' << ok << ' ' << s0 << ' ' << s1 << '\n';
        if (i & 1) {
            a[i] += s1;
            if (a[i] > b[i]) {
                ok = 0;
            } else {
                s1 += b[i] - a[i];
                s0 -= b[i] - a[i];
            }
        } else {
            a[i] += s0;
            if (a[i] > b[i]) {
                ok = 0;
            } else {
                s0 += b[i] - a[i];
                s1 -= b[i] - a[i];
            }
        } 
    }
    cout << '\n';
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
