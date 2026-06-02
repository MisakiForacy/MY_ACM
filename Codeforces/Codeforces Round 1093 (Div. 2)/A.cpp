#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    sort(all(a), greater());
    int ok = 1;
    // for (int i = 1;i < n;i ++) if (a[i] == a[i - 1]) ok = 0;
    if (n > 1 && a[0] == a[1]) ok = 0;
    if (ok) {
        for (int x : a) cout << x << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}