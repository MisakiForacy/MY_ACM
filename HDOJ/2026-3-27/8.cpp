#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), p(n + 1, 0), s(n + 2, 0);
    vector<LL> mir(n + 2, inf), mil(n + 2, inf);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) p[i] = p[i - 1] + a[i];
    for (int i = n;i >= 1;i --) s[i] = s[i + 1] + a[i];
    for (int i = n;i >= 1;i --) mir[i] = min(mir[i + 1], p[i]);
    for (int i = 1;i <= n;i ++) mil[i] = min(mil[i - 1], p[i]);
    LL ans = n + 1;
    for (LL i = 1;i <= n;i ++) {
        if (mir[i] - p[i - 1] < 0) continue;
        if (mil[i] + s[i] < 0) continue;
        ans = min(ans, i);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}