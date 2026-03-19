#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve () {
    LL n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (n == m && n == 3) {
        cout << 8 << '\n';
    } else if (n == 2) {
        cout << (m - 1) / 2 + 1 << '\n';
    } else if (n == 1) {
        cout << 1 << '\n';
    } else {
        cout << n * m << '\n';
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}