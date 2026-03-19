#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

/*
6
7
1 1 1 -1 1 1 -1
4
1 0 -1 0
4
0 -1 -1 0
1
0
2
0 0
1 
-1
*/

void solve() {
    int n, ok = 1;
    cin >> n;
    vector<int> a(n + 1, 0), p(n + 1, 0), q(n + 1, 0), s(n + 2, n + 1);
    p[0] = q[0] = 1;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) {
        if (a[i] == 1 || a[i] == 0) {
            p[i] = p[i - 1] + 1;
            q[i] = q[i - 1] + 1;
        } else {
            p[i] = p[i - 1];
            q[i] = q[i - 1] - 1;
        }
        if (q[i] <= 0) {
            cout << -1 << '\n';
            return;
        }
    }
    int use = 0;
    for (int i = n;i >= 1;i --) s[i] = min(s[i + 1], q[i]);
    for (int i = 1;i <= n;i ++) {
        if (a[i] == 0) {
            if (s[i] - 2 * (use + 1) >= 1) {
                use += 1;
            }
        }
    }
    // cout << p[n] << ' ' << q[n] << ' ' << use << '\n';
    p[n] -= use, q[n] -= use * 2;
    int g = __gcd(p[n], q[n]);
    cout << p[n] / g << ' ' << q[n] / g << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.tix", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}