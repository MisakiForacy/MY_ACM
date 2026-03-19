#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n, k;
    cin >> n >> k;
    if (k & 1) {
        for (int i = 1;i <= k;i ++) {
            cout << n << ' ';
        }
        cout << '\n';
    } else {
        int cnt = 0;
        LL x = n, y, z = n;
        for (int i = 31;i >= 0;i --) {
            if (n >> i & 1) {
                cnt ++;
            }
            if (cnt >= 2) x ^= (1LL << i);
        }
        y = x ^ n;
        if (k == 2) {
            cout << x << ' ' << y << '\n';
        } else {
            cout << x << ' ' << y << ' ';
            for (int i = 1;i <= k - 2;i ++) cout << n << ' ';
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}