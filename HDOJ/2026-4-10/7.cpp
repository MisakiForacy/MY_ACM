#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int mx = 0, n, S, ok = 1;
    cin >> n >> S;
    for (int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        mx = max(mx, x);
        if (x != 0 && x != S) ok = 0;
    }
    if (mx == 0 && S != 0) ok = 0;
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}