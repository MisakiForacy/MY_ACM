#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, m, ok = 1;
    cin >> n >> m;
    vector<LL> a(n + 1, -1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    // if (a[1] == m - 1) ok = 0;
    for (int i = 1;i <= n;i ++) {
        int len = 1;
        while (i + len <= n && a[i] == a[i + len]) len ++;
        i += len - 1;
        if (len >= m) ok = 0;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}