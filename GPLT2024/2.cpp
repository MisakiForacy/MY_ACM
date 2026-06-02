#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 2) {
        cout << "-\n";
        cout << "stop\n";
    } else if (b == 1) {
        cout << "-\n";
        if (a == 0 || a == 2) {
            cout << "stop\n";
        } else {
            cout << "move\n";
        }
    } else {
        if (a == 1) {
            cout << "dudu\n";
            cout << "move\n";
        } else if (a == 0) {
            cout << "biii\n";
            cout << "stop\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}