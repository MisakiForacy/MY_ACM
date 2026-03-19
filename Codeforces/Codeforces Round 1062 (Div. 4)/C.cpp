#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    int ok = 0;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 2;i <= n;i ++) {
        if ((a[i] & 1) != (a[i - 1] & 1)) {
            ok = 1;
        }
    }
    if (ok) {
        sort(all(a));
        for (int i = 1;i <= n;i ++) cout << a[i] << ' ';
        cout << '\n';
    } else {
        for (int i = 1;i <= n;i ++) cout << a[i] << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}