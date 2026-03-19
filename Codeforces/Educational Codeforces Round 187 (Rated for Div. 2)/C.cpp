#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL s, m;
    cin >> s >> m;
    LL lo = 1, hi = 1e18;
    auto check = [&](LL n) -> int {
        LL S = s;
        for (int j = 63;j >= 0;j --) {
            if (m >> j & 1) {
                LL k = min(n, S / (1LL << j));
                S -= k * (1LL << j);
            }
        }
        return S == 0;
    };
    while (lo < hi) {
        LL mid = lo + hi >> 1;
        if (check(mid)) hi = mid - 1;
        else lo = mid + 1;
    }
    if (!check(lo)) lo ++;
    if (lo > LL(1e18)) {
        cout << -1 << '\n';
    } else {
        cout << lo << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}