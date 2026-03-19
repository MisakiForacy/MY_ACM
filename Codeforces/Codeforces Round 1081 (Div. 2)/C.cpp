#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e18;

void solve() {
    LL n, h, k;
    cin >> n >> h >> k;
    vector<LL> a(n + 1, 0), p(n + 1, 0);
    vector<LL> Mi(n + 1, inf), Mx(n + 2, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], Mi[i] = min(Mi[i - 1], a[i]);
    for (int i = n;i >= 1;i --) Mx[i] = max(Mx[i + 1], a[i]);
    for (int i = 1;i <= n;i ++) p[i] = p[i - 1] + a[i];
    LL ans = n * (h / p[n]) + k * (h / p[n] - 1 + (h % p[n] ? 1 : 0));
    h = h % p[n];
    if (!h) {
        cout << ans << '\n';
        return;
    }
    for (int i = 1;i <= n;i ++) {
        if (h - (p[i] + Mx[i + 1] - Mi[i]) <= 0) {
            cout << ans + i << '\n';
            return;
        }
        if (h - p[i] <= 0) {
            cout << ans + i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}