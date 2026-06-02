#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n + 1, 0), b(n + 2, 0), p(n + 3, 0), s(n + 3, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n + 1;i ++) cin >> b[i];
    sort(all(a)), sort(all(b));
    for (int i = 1;i <= n;i ++) p[i] = p[i - 1] + a[i] * b[i];
    for (int i = n + 1;i >= 2;i --) {
        s[i] = s[i + 1] + a[i - 1] * b[i];
        if (s[i] >= m) {
            cout << 0 << '\n';
            return;
        }
    }
    auto check = [&](LL x) -> int {
        int idx = upper_bound(all(a), x) - a.begin();
        LL res = x * b[idx] + p[idx - 1] + s[idx + 1];
        return res >= m;
    };
    LL lo = 0, hi = m;
    while (lo < hi) {
        LL mid = lo + hi >> 1;
        if (check(mid))
            hi = mid;
        else 
            lo = mid + 1;
    }
    cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}