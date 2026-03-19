#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    int ans = n;
    vector<int> Mx(n + 1, 0), Mi(n + 2, n + 1);
    for (int i = 1;i <= n;i ++) Mx[i] = max(Mx[i - 1], a[i]);
    for (int i = n;i >= 1;i --) Mi[i] = min(Mi[i + 1], a[i]);
    for (int i = n;i >= 1;i --) {
        if (Mx[i - 1] > Mi[i + 1] || Mx[i - 1] > a[i]) ans --;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}