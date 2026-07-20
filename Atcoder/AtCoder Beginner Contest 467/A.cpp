#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    double w, h;
    cin >> h >> w;
    w *= 10000;
    if (w / (h * h) >= 25) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
