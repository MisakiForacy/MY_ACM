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
    LL sum = 0;
    vector<LL> a(n + 1, 0), p(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        sum += a[i];
    }
    LL dat = 1e15;
    int r = 1;
    for (int i = 1;i <= n;i ++) {
        r = max(i, r);
        while (r <= n && p[r] - p[i - 1] <= sum / 2) {
            r ++;
            dat = min(dat, sum - 2 * (p[r] - p[i - 1]));
        }
    }
    LL x = sum - dat >> 2;
    LL y = sum - x;
    cout << x * y % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
