#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    LL p, q, x, y;
    cin >> p >> q >> x >> y;
    int ok = 1;
    if (!(p <= x && x <= p + 99)) ok = 0;
    if (!(q <= y && y <= q + 99)) ok = 0;
    cout << (ok ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}