#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL n, k, x;
    cin >> n >> k;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<LL> p(k + 2, 0), l(n + 1, -1), r(n + 1, n + 1);
    vector<LL> lx(n + 1, 0), rx(n + 1, 0);
    for (int i = 1;i <= k;i ++) cin >> p[i];
    p[k + 1] = n + 1;
    x = p[1];
    int pp = 0, ll = 0, rr = 0;
    for (int i = 1;i <= x;i ++) {
        if ((a[i] ^ pp) != a[x]) {
            pp ^= 1;
            ll ++;
        }
    }
    pp = 0;
    for (int i = p[2] - 1;i >= x;i --) {
        if ((a[i] ^ pp) != a[x]) {
            pp ^= 1;
            rr ++;
        }
    }
    // cout << "ok\n";
    LL ans = max(ll, rr);
    cout << ans << '\n';
    for (int t = 2;t <= k;t ++) {
        pp = 0;
        for (int i = p[t + 1] - 1;i >= p[t];i --) {
            if ((a[i] ^ pp) != a[x]) {
                pp ^= 1;
                ans ++;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}