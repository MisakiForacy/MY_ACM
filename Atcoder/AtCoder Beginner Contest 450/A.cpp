#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    for (int i = n;i >= 2;i --) {
        cout << i << ',';
    }
    cout << 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}