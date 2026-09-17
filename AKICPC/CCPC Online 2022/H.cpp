#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    LL L, R, K;
    cin >> L >> R >> K;
    vector<LL> ans;
    for (LL n = 60;n >= 0;n --) {
        if (1LL << n > (R - L + 1)) continue;
        LL lo, hi;
        lo = 
        hi = 
        auto check = [&](LL d) -> bool {
            LL n1 = R / d, n2 = (L - 1) / d;
            LL S = (n1 + n2 + 1) * (n1 - n2) * d;
            return S <= 2 * K;
        };
        while (lo < hi) {
            LL mid = lo + hi >> 1;
            if (check(mid)) 
                lo = mid;
            else   
                hi = mid - 1;
        }
        LL n1 = R / lo, n2 = (L - 1) / lo;
        LL S = (n1 + n2 + 1) * (n1 - n2) * d;
        if (S == 2 * K) ans.push_back(lo);
    }
    if (!ans.size()) {
        cout << "No Solution\n";
        return;
    }
    cout << ans.size() << '\n';
    for (LL x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}