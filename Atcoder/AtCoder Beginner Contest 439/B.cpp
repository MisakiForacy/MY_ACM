#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, t = 0;
    cin >> n;
    while (n != 1 && t < 1000000) {
        LL Sm = 0;
        while (n) {
            Sm += (n % 10) * (n % 10);
            n /= 10;
        }
        n = Sm;
        t += 1;
    } 
    if (n == 1) {
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