#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL MOD = 998244353;

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n + 1, 0), b(m + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= m;i ++) cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    vector<LL> p(n + 1, 0);
    for (int i = 1;i <= n;i ++) p[i] = p[i - 1] + a[i];
    LL Sm = 0;
    for (int i = 1;i <= m;i ++) {
        LL px = upper_bound(all(a), b[i]) - a.begin() - 1;
        // cout << px << '\n';
        Sm += b[i] * px - p[px];
        Sm %= MOD;
        Sm += (p[n] - p[px]) - b[i] * (n - px);
        Sm %= MOD;
    }
    cout << Sm << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}