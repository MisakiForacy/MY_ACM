#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    int n, m, v;
    cin >> n >> m;
    vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1;i <= m;i ++) {
        cin >> v;
        int ans = 0;
        if (!c[v]) {
            for (int k = 1;k * v <= n;k ++) {
                ans += !b[k * v];
                b[k * v] = 1;
            }
        } else {
            ans = 0;
        }
        c[v] = 1;
        if (ans) {
            cout << ans << '\n';
        } else {
            cout << "the lights are already on!\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}