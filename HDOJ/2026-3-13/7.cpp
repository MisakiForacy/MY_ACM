#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 60

using namespace std;
using LL = long long;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0), p(n + 1, 0), pre(n + 2, -(10 * inf)), suf(n + 2, -(10 * inf));
    LL mx = -inf, mi = 0;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        mi = min(mi, p[i - 1]);
        pre[i] = max(pre[i - 1], p[i] - mi);
    }
    mi = 0;
    vector<LL> s(n + 2, 0);
    for (int i = n;i >= 1;i --) {
        s[i] = s[i + 1] + a[i];
        mi = min(mi, s[i + 1]);
        suf[i] = max(suf[i + 1], s[i] - mi);
    }
    LL ans = - inf;
    for (int i = 3;i <= n - 2;i ++) {
        ans = max(ans, a[i] + pre[i - 2] + suf[i + 2]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}