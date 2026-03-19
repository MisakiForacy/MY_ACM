#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const int N = 2e5 + 10;
const LL inf = 1e18 + 1;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    LL x, y;
    cin >> x >> y;
    if ((x - 2 * y) % 3 || x - 2 * y < 0) {
        cout << "NO\n";
    } else {
        LL Mi = max(0LL, -y);
        LL Mx = (x - 2 * y) / 6;
        if (Mi <= Mx) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}