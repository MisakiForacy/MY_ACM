#include <bits/stdc++.h>

#define x first 
#define y second

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(all(a));
    LL Sm = min(abs(a.back() - a[1]), 8 - abs(a.back() - a[1]));
    LL Mx = min(abs(a.back() - a[1]), 8 - abs(a.back() - a[1]));
    for (int i = 2;i <= n;i ++) {
        Sm += min(abs(a[i] - a[i - 1]), 8 - abs(a[i] - a[i - 1]));
        Mx = max(Mx, min(abs(a[i] - a[i - 1]), 8 - abs(a[i] - a[i - 1])));
    }
    cout << Sm - Mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}