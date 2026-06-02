#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, m, x, cnt = 0;
    cin >> n >> m >> x;
    vector<int> a(n + 1, 0), b(m + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= m;i ++) cin >> b[i];
    for (int i = 1;i <= n;i ++) if (a[i] >= x) cnt ++;
    for (int i = 1;i <= m;i ++) if (b[i] <= x) cnt ++;
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}