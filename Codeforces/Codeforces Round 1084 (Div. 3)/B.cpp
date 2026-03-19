#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int mx = 0, ok = 0;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (a[i] < mx) {
            ok = 1;
        }
        mx = max(mx, a[i]);
    }
    cout << (ok ? 1 : n) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}