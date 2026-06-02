#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    int ok = 1;
    for (int i = 1;i <= n;i ++) {
        if (i & 1) {
            if ((a[i] & 1) != (a[1] & 1)) ok = 0;
        } else {
            if ((a[i] & 1) != (a[2] & 1)) ok = 0;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}