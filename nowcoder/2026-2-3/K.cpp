#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    // 1 2 3
    // 1 + 2 + 3 == 1 * 2 * 3
    if (n == 1) {
        cout << "YES\n";
        cout << 1 << '\n';
    } else if (n == 3) {
        cout << "YES\n";
        cout << "1 2 3\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}