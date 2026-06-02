#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n;
    LL ans = 0;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 2;i <= n;i ++) {
        ans = max(ans, min(a[i - 1], a[i]) * max(a[i - 1], a[i]));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}