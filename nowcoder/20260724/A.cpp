#include <bits/stdc++.h>

#define x first 

#define y second 

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> p(n + 1);
    vector<array<LL, 4>> p2(60);
    for (int i = 1;i <= n;i ++) {
        cin >> p[i];
        for (int j = 30;j >= 0;j --) {
            p2[j][(p[i] >> j) % 4] ++;
        }
    } 
    int m;
    cin >> m;
    while (m --) {
        LL op, x;
        cin >> op >> x;
        LL ans = 0;
        for (int j = 30;j >= 0;j --) {
            auto old = p2[j];
            array<LL, 4> now{};
            int d = (x >> j) % 4;
            for (int t1 = 0;t1 < 4;t1 ++) {
                if (old[t1] == 0) continue;
                int nu;
                if (op == 1) {
                    nu = t1 & d;
                } else if (op == 2) {
                    nu = t1 | d;
                } else {
                    nu = t1 ^ d;
                }
                now[nu] += old[t1];
            }
            p2[j] = now;
            // cout << p2[j][1] << ' ';
            ans += p2[j][1];
        }
        // cout << '\n';
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}