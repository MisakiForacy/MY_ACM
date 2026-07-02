#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    LL dat = 0;
    for (int i = 1;i <= n;i ++) cout << b[i] - a[i] << ' ';
    cout << '\n';
    for (int i = 1;i <= n;i ++) dat += b[i] - a[i];
    if (dat < 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
