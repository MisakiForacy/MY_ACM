#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    LL n, m;
    cin >> n >> m;
    LL v1, v2;
    if ((n & 1) || (m & 1)) {
        cout << (n * m + 1) / 2 << '\n';
    } else {
        auto cal = [&]() -> LL {
            LL h = (n - 2) / 2;
            return (h * m + 1) / 2 * 2;
        };
        v1 = cal();
        swap(n, m);
        v2 = cal();
        cout << max(v1, v2) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}