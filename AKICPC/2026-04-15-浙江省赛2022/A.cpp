#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
    } else if (a < b) {
        if ((b - a) & 1) {
            cout << 1 << '\n';
        } else {
            if ((b - a) / 2 % 2 == 0) {
                cout << 3 << '\n';
            } else {
                cout << 2 << '\n';
            }
        }
    } else {
        if ((a - b) & 1) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}