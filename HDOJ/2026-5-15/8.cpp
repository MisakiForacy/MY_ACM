#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    LL a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    // cout << a + b << '\n';
    if (a - 1 == 0) {
        // cout << a + b << '\n';
        if (b > a * 2) {
            cout << 2 * a << '\n';
        } else {
            cout << a + b << '\n';
        }
    } else {
        cout << 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}