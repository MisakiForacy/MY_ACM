#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

using Z = __int128_t;

void solve () {
    LL x, y, k;
    cin >> x >> y >> k;
    Z res = 1e12, cur = k;
    for (int i = 1;i <= x;i ++) {
        res -= res / y;
        if (res < k) {
            cout << -1 << '\n';
            return;
        }
        cur = (cur * y - 1) / (y - 1);
    }
    cout << LL(cur) << '\n';
}

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}