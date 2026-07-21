#include <bits/stdc++.h>

#define x first 
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<LL> v(n), a(n + 1), p(n + 1);
    for (int i = 1;i < n;i ++) cin >> v[i], p[i + 1] = p[i] + v[i];
    for (int i = 1;i <= n;i ++) cin >> a[i];
    int nxt = 2;
    LL ans = 0, sum = 0;
    for (int i = 1;i < n;) {
        cout << i << ':';
        while (nxt < n && a[nxt] >= a[i]) nxt ++;
        LL x = p[nxt] - p[i];
        cout << x << '\n';
        sum += (x + d - 1) / d;
        ans += (sum - x - d + 1) / d * a[i];
        i = nxt;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}