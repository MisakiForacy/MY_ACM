#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    LL a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    while (c >= x || b >= y) {
        if (c >= x) {
            b += c / x;
            c %= x;
        }
        if (b >= y) {
            a += b / y;
            c += b / y;
            b %= y;
        }
    }
    cout << a << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}