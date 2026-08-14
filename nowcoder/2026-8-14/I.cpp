#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    LL x, a, b;
    cin >> x >> a >> b;
    // LL lo = 0, hi = 1e9;
    // LL A = (a + 1) * a / 2 + (a - a);
    // LL B = b * a;
    auto case1 = [&]() -> LL {
        LL d = a - 1;
        LL s = a;
        LL lo = 1, hi = x; 
        auto check = [&](LL x) -> bool {
            return s + (x - 1) * d < x;
        };
        while (lo < hi) {
            LL mid = lo + hi >> 1;
            if (check(mid))
                lo = mid + 1;
            else 
                hi = mid;
        }
        return lo;
    };
    auto case2 = [&]() -> LL {
        return (x + b - 1) / b;
    };
    auto case3 = [&]() -> LL {
        
    };
    // while (lo < hi) {
    //     LL mid = lo + hi >> 1;
    //     if (check(mid))
    //         lo = mid + 1;
    //     else 
    //         hi = mid;
    // }
    // cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
