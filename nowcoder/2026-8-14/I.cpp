#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    LL x, a, b;
    cin >> x >> a >> b;
    LL lo = 1, hi = x;
    LL s = a, d = a - 1;
    auto check = [&](LL mid) -> bool {
        auto cal = [&](LL len) -> LL {
            LL f = (len ? s + (len - 1) * d : 0);
            LL fs = max(0LL, f - 1);
            LL ff = max(0LL, fs - (mid - len) + 1);
            LL ct = fs - ff + 1;
            LL a1 = (s + f) * len / 2;
            LL a2 = (mid - len) * b + ct * (fs + ff) / 2;
            return a1 + a2;
        };
        LL l = 0, r = mid;
        while (l < r) {
            LL m = l + r >> 1;
            if (cal(m) < cal(m + 1))
                l = m + 1;
            else 
                r = m;
        }
        // cout << mid << ' ' << l << ' ' << cal(l) << '\n';
        return cal(l) < x;
    };
    while (lo < hi) {
        LL mid = lo + hi >> 1;
        if (check(mid))
            lo = mid + 1;
        else 
            hi = mid;
    }
    cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
