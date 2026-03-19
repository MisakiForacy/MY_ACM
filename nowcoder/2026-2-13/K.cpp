#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

void solve() {
    LL m, n, z;
    cin >> m >> n >> z;
    LL x = 0;
    LL v = z % (m + n);
    if (v == 0) {
        cout << 1;
    } else if (v <= m) {
        cout << 0;
    } else {
        cout << 1;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}