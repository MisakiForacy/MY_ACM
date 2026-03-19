#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), f(n + 1, 0), odd, even;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (a[i] & 1) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }
    int ok = 1;
    for (int i = 1;i < siz(odd);i ++) if (odd[i] < odd[i - 1]) ok = 0;
    for (int i = 1;i < siz(even);i ++) if (even[i] < even[i - 1]) ok = 0;
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}