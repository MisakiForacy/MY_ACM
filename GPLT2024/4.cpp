#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(m + 1);
    LL s = 0;
    for (int i = 1;i <= m;i ++) cin >> a[i], s += a[i];
    cout << max(s - n * (m - 1), 0LL) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}