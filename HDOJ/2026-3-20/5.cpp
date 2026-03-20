#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    LL n, k;
    cin >> n >> k;
    if (k >= 60) {
        cout << 1 << '\n';
    } else {
        auto check = [&](LL x) -> bool {
            LL res = 1;
            for (int i = 1;i <= k;i ++) {
                res *= x;
                if (res > n) return 0;
            }
            return res <= n;
        };
        LL lo = 1, hi = 100000;
        while (lo < hi) {
            LL mid = lo + hi >> 1;
            if (!check(mid)) hi = mid;
            else lo = mid + 1;
        }
        if (!check(lo)) lo --;
        cout << lo << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}