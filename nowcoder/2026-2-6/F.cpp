#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL n, p = 1;
    cin >> n;
    while (1) {
        LL x = n * p;
        if ((-x & x) > n) {
            cout << x << ' ' << (x ^ n) << '\n';
            return;
        }
        p *= 2;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}