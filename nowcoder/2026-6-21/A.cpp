#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const LL inf = 1e15;

const LL mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0), p(n + 1, 0);
    LL sum = 0;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        sum += a[i];
    }
    LL dat = 1e15;
    for (int i = 0;i < n;i ++) {
        int pos1 = lower_bound(all(p), p[i] + sum / 2) - p.begin();
        int pos2 = lower_bound(all(p), p[i] + sum / 2) - p.begin() - 1;
        pos1 = min(pos1, n);
        pos2 = max(i, pos2);
        dat = min(dat, abs(sum - 2 * (p[pos1] - p[i])));
        dat = min(dat, abs(sum - 2 * (p[pos2] - p[i])));
    }
    LL x = sum - dat >> 1;
    LL y = sum - x;
    cout << (x % mod) * (y % mod) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
