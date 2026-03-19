#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve () {
    LL l, r;
    cin >> l >> r;
    LL a = r / 3 - (l - 1) / 3;
    LL b = (r + 1) / 3 - l / 3;
    LL c = (r + 2) / 3 - (l + 1) / 3;
    cout << c << ' ' << b << ' ' << a << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}